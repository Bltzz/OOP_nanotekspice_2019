/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4094.cpp
*/

#include "Component4094.hpp"
#include "ComponentClock.hpp"
#include <iostream>
// #include <vector>

Component4094::Component4094(std::string name)
{
    this->name = name;
    this->type = "4094";
    this->numPins = 15;
    this->internalStates = {nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE};

    pins[1] = new Pins(Pins::Type::INPUT, 1);                          // Strobe
    pins[2] = new Pins(Pins::Type::INPUT, 2);                          // Data
    pins[3] = new Pins(Pins::Type::CLOCK, 3);                          // Clock
    pins[4] = new Pins(Pins::Type::OUTPUT, 4);                         // Q1
    pins[5] = new Pins(Pins::Type::OUTPUT, 5);                         // Q2
    pins[6] = new Pins(Pins::Type::OUTPUT, 6);                         // Q3
    pins[7] = new Pins(Pins::Type::OUTPUT, 7);                         // Q4
    pins[14] = new Pins(Pins::Type::OUTPUT, 14);                       // Q5
    pins[13] = new Pins(Pins::Type::OUTPUT, 13);                       // Q6
    pins[12] = new Pins(Pins::Type::OUTPUT, 12);                       // Q7
    pins[11] = new Pins(Pins::Type::OUTPUT, 11);                       // Q8
    pins[10] = new Pins(Pins::Type::OUTPUT, 10, nts::Tristate::FALSE); // NOT Qs
    pins[9] = new Pins(Pins::Type::OUTPUT, 9, nts::Tristate::FALSE);   // Qs
    pins[15] = new Pins(Pins::Type::INPUT, 15);                        // Output Enable
}

Component4094::~Component4094()
{
    for (auto it : getMap())
    {
        delete it.second;
        getMap().erase(it.first);
    }
}

bool Component4094::checkOutputEnable()
{
    if (this->getMap().at(15)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component4094::checkClock()
{
    ComponentClock *tmp = dynamic_cast<ComponentClock *>(this->getMap().at(3)->getComponent());
    if (tmp->getValue() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component4094::checkStrobe()
{
    ComponentInput *tmp = dynamic_cast<ComponentInput *>(this->getMap().at(1)->getComponent());
    if (tmp->compute(1) == nts::Tristate::TRUE)
        return true;
    return false;
}

std::vector<nts::Tristate> Component4094::_computeOnce(nts::Tristate data)
{
    std::vector<int> pinOrder = {4, 5, 6, 7, 14, 13, 12, 11};
    std::vector<nts::Tristate> tmp(this->internalStates.size() + 1);

    if (checkClock() && !checkStrobe())
    {
        pins.at(9)->setState(internalStates.at(6));
        return this->internalStates;
    }
    if (checkClock() && checkStrobe())
    {
        tmp = {};
        tmp.push_back(data);
        for (long unsigned int i = 0; i < this->internalStates.size(); i++)
        {
            tmp.push_back(this->internalStates.at(i));
        }
        tmp.pop_back();
        internalStates.clear();
        for (auto tmp1 : tmp)
            this->internalStates.push_back(tmp1);
        pins.at(9)->setState(internalStates.at(6));
        return internalStates;
    }
    if (!checkClock() && checkStrobe() && data == nts::Tristate::TRUE)
    {
        pins.at(10)->setState(internalStates.at(6));
    }

    return internalStates;
}

nts::Tristate Component4094::compute(std::size_t pin = 1)
{
    nts::Tristate data = pins.at(2)->getComponent()->compute(pins.at(2)->getPin());

    if (pin == 0 || (int)pin > this->numPins || pin == 8)
        throw InvalidArgumentException("Pin does not exist", this->getName());
    std::vector<int> pinOrder = {4, 5, 6, 7, 14, 13, 12, 11};

    if (pin == 4)
    {
        this->internalStates = _computeOnce(data);
        if (this->checkOutputEnable())
        {
            for (long unsigned int i = 0; i < pinOrder.size() && i < this->internalStates.size(); i++)
            {
                getMap().at(pinOrder.at(i))->setState(this->internalStates.at(i));
                if (getMap().at(pinOrder.at(i))->getState() == nts::Tristate::UNDEFINED)
                    getMap().at(pinOrder.at(i))->setState(nts::Tristate::FALSE);
            }
        }
    }
    return this->getMap().at(pin)->getState();
}