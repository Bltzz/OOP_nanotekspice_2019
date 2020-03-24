/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4017.cpp
*/

#include "Component4017.hpp"
#include "ComponentClock.hpp"
#include <exception>
#include <iostream>
#include <vector>

Component4017::Component4017(std::string name)
{
    this->name = name;
    this->type = "4017";
    this->numPins = 15;

    pins[3] = new Pins(Pins::Type::OUTPUT, 3, nts::Tristate::TRUE);   // Q0
    pins[2] = new Pins(Pins::Type::OUTPUT, 2);                        // Q1
    pins[4] = new Pins(Pins::Type::OUTPUT, 4);                        // Q2
    pins[7] = new Pins(Pins::Type::OUTPUT, 7);                        // Q3
    pins[10] = new Pins(Pins::Type::OUTPUT, 10);                      // Q4
    pins[1] = new Pins(Pins::Type::OUTPUT, 1);                        // Q5
    pins[5] = new Pins(Pins::Type::OUTPUT, 5);                        // Q6
    pins[6] = new Pins(Pins::Type::OUTPUT, 6);                        // Q7
    pins[9] = new Pins(Pins::Type::OUTPUT, 9);                        // Q8
    pins[11] = new Pins(Pins::Type::OUTPUT, 11);                      // Q9
    pins[12] = new Pins(Pins::Type::OUTPUT, 12, nts::Tristate::TRUE); // carry output //1 - 11 Output (Pin 8 = ground -> irrelevant)
    pins[13] = new Pins(Pins::Type::CLOCK, 13);                       // clock input 1 to 0 triggered
    pins[14] = new Pins(Pins::Type::CLOCK, 14);                       // clock input 0 to 1 triggered
    pins[15] = new Pins(Pins::Type::INPUT, 15);                       // Master reset
}

Component4017::~Component4017() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

bool Component4017::stateToBool(nts::Tristate t)
{
    switch (t)
    {
    case nts::Tristate::TRUE:
        return true;
    case nts::Tristate::FALSE:
        return false;
    default:
        return false;
        break;
    }
}

bool Component4017::isUndefined(const nts::Tristate t, const nts::Tristate t2)
{
    if ((t != nts::Tristate::UNDEFINED) && (t2 != nts::Tristate::UNDEFINED))
        return true;
    return false;
}

bool Component4017::checkMaster()
{
    if (this->getMap().at(15)->getState() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component4017::checkClockHL()
{
    ComponentClock *tmp = dynamic_cast<ComponentClock *>(this->getMap().at(13)->getComponent());
    if (tmp->getValue() == nts::Tristate::FALSE)
        return false;
    return true;
}

bool Component4017::checkClockLH()
{
    ComponentClock *tmp = dynamic_cast<ComponentClock *>(this->getMap().at(14)->getComponent());
    if (tmp->getValue() == nts::Tristate::TRUE){
        return true;
    }
    return false;
}

nts::Tristate Component4017::_computeOnce(std::size_t pin)
{
    std::vector<int> pinOrder = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11};
    if (this->checkClockLH() && stateToBool(this->getMap().at(14)->getComponent()->getMap().at(1)->getState()))
    {
        for (int i = 0; i < (int)pinOrder.size(); i++)
        {
            auto tmp = getMap().at(pinOrder.at(i));
            if (tmp->getState() == nts::Tristate::TRUE)
            {
                if (i < 5 || i == 9)
                {
                    this->getMap().at(12)->setState(nts::Tristate::TRUE);
                }
                else
                    this->getMap().at(12)->setState(nts::Tristate::FALSE);
                try
                {
                    getMap().at(pinOrder.at(i))->setState(nts::Tristate::FALSE);
                    getMap().at(pinOrder.at(i + 1))->setState(nts::Tristate::TRUE);

                    return this->getMap().at(pin)->getState();
                }
                catch (std::out_of_range &e)
                {
                    this->getMap().at(3)->setState(nts::Tristate::TRUE);
                    this->getMap().at(12)->setState(nts::Tristate::TRUE);
                    //return this->getMap().at(pin)->getState();
                }
            }
            else
            {
                getMap().at(pinOrder.at(i))->setState(nts::Tristate::FALSE);
            }
        }
    }
    else if (this->checkClockHL() && checkClockLH() && stateToBool(this->getMap().at(13)->getComponent()->getMap().at(1)->getState()))
    {
        for (int i = 0; i < (int)pinOrder.size(); i++)
        {
            auto tmp = getMap().at(pinOrder.at(i));
            if (tmp->getType() == Pins::Type::OUTPUT && tmp->getState() == nts::Tristate::TRUE)
            {
                if (i < 5 || i == 9)
                    this->getMap().at(12)->setState(nts::Tristate::TRUE);
                else
                    this->getMap().at(12)->setState(nts::Tristate::FALSE);
                try
                {
                    getMap().at(pinOrder.at(i))->setState(nts::Tristate::FALSE);
                    getMap().at(pinOrder.at(i + 1))->setState(nts::Tristate::TRUE);
                    return this->getMap().at(pin)->getState();
                }
                catch (std::out_of_range &e)
                {
                    this->getMap().at(3)->setState(nts::Tristate::TRUE);
                    this->getMap().at(12)->setState(nts::Tristate::TRUE);
                    //return this->getMap().at(pin)->getState();
                }
            }
            else
            {
                getMap().at(pinOrder.at(i))->setState(nts::Tristate::FALSE);
            }
        }
    }
    return this->pins.at(pin)->getState();
}

nts::Tristate Component4017::compute(std::size_t pin = 1)
{
    if (pin == 0 || (int)pin > this->numPins || pin == 8)
        throw InvalidArgumentException("Pin does not exist", this->getName());
    for (auto tmp : this->getMap())
        if (tmp.second->getType() == Pins::Type::OUTPUT && tmp.second->getState() != nts::Tristate::TRUE)
            tmp.second->setState(nts::Tristate::FALSE);
    if (this->checkMaster())
    {
        for (auto tmp : this->getMap())
            if (tmp.second->getType() == Pins::Type::OUTPUT)
                tmp.second->setState(nts::Tristate::FALSE);
        this->getMap().at(3)->setState(nts::Tristate::TRUE);
        this->getMap().at(12)->setState(nts::Tristate::TRUE);
        return this->getMap().at(pin)->getState();
    }
    if (pin == 12)
       return _computeOnce(pin);
    if (this->getMap().at(pin)->getType() != Pins::Type::OUTPUT)
        return nts::Tristate::UNDEFINED;
    return this->pins.at(pin)->getState();
}