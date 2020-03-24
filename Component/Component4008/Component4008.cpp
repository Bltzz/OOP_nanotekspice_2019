/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4008.cpp
*/

#include "Component4008.hpp"
#include <iostream>

Component4008::Component4008(std::string name)
{
    this->name = name;
    this->type = "4008";
    this->numPins = 16;

    pins[15] = new Pins(Pins::Type::INPUT, 15);  //second number input ***$
    pins[1] = new Pins(Pins::Type::INPUT, 1);    //first number input  ***$
    pins[2] = new Pins(Pins::Type::INPUT, 2);    //second number input **$*
    pins[3] = new Pins(Pins::Type::INPUT, 3);    //first number input  **$*
    pins[4] = new Pins(Pins::Type::INPUT, 4);    //second number input *$**
    pins[5] = new Pins(Pins::Type::INPUT, 5);    //first number input  *$**
    pins[6] = new Pins(Pins::Type::INPUT, 6);    //second number input $***
    pins[7] = new Pins(Pins::Type::INPUT, 7);    //first number input  $***
    pins[9] = new Pins(Pins::Type::INPUT, 9);    //carrier input
    pins[10] = new Pins(Pins::Type::OUTPUT, 10); //output ***$
    pins[11] = new Pins(Pins::Type::OUTPUT, 11); //output **$*
    pins[12] = new Pins(Pins::Type::OUTPUT, 12); //output *$**
    pins[13] = new Pins(Pins::Type::OUTPUT, 13); //output $***
    pins[14] = new Pins(Pins::Type::OUTPUT, 14); //carrier Output
}

Component4008::~Component4008() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

std::tuple<nts::Tristate, nts::Tristate> Component4008::gate(bool i1, bool i2, bool carrier)
{
    if ((i1 + i2 + carrier) == 3)
        return std::make_tuple(nts::Tristate::TRUE, nts::Tristate::TRUE);
    else if ((i1 + i2 + carrier) == 1)
        return std::make_tuple(nts::Tristate::TRUE, nts::Tristate::FALSE);
    else if ((i1 + i2 + carrier) == 0)
        return std::make_tuple(nts::Tristate::FALSE, nts::Tristate::FALSE);
    return std::make_tuple(nts::Tristate::FALSE, nts::Tristate::TRUE);
}

bool Component4008::stateToBool(nts::Tristate t)
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

bool Component4008::isUndefined(const nts::Tristate t, const nts::Tristate t2)
{
    if ((t != nts::Tristate::UNDEFINED) && (t2 != nts::Tristate::UNDEFINED))
        return true;
    return false;
}

nts::Tristate Component4008::compute(std::size_t pin = 1)
{
    nts::Tristate tmpState1;
    nts::Tristate carrier;
    if (this->getMap().at(pin)->getType() != Pins::OUTPUT)
        throw InvalidArgumentException("Pin type does not match OUTPUT", this->getName());
    if (isUndefined(this->getMap().at(1)->getComponent()->compute(this->getMap().at(1)->getPin()), this->getMap().at(15)->getComponent()->compute(this->getMap().at(15)->getPin())) && this->getMap().at(9)->getComponent()->compute() != nts::Tristate::UNDEFINED)
    { //1 Bit adder
        bool tmp1 = stateToBool(this->getMap().at(1)->getComponent()->compute(this->getMap().at(1)->getPin()));
        bool tmp2 = stateToBool(this->getMap().at(15)->getComponent()->compute(this->getMap().at(15)->getPin()));
        bool car = stateToBool(this->getMap().at(9)->getComponent()->compute(this->getMap().at(9)->getPin()));
        tmpState1 = std::get<0>(gate(tmp1, tmp2, car));
        carrier = std::get<1>(gate(tmp1, tmp2, car));
        this->getMap().at(10)->setState(tmpState1);
        this->getMap().at(14)->setState(carrier);

    }
    else
    {
        tmpState1 = nts::Tristate::UNDEFINED;
        this->getMap().at(10)->setState(tmpState1);
    }
    if (pin == 10)
        return tmpState1;

    if (isUndefined(this->getMap().at(1)->getComponent()->compute(this->getMap().at(1)->getPin()), this->getMap().at(15)->getComponent()->compute(this->getMap().at(15)->getPin())))
    { //2 Bit Adder
        bool tmp1 = stateToBool(this->getMap().at(2)->getComponent()->compute(this->getMap().at(2)->getPin()));
        bool tmp2 = stateToBool(this->getMap().at(3)->getComponent()->compute(this->getMap().at(3)->getPin()));
        bool car = stateToBool(carrier);
        tmpState1 = std::get<0>(gate(tmp1, tmp2, car));
        carrier = std::get<1>(gate(tmp1, tmp2, car));
        this->getMap().at(11)->setState(tmpState1);
        this->getMap().at(14)->setState(carrier);
    }
    else
    {
        tmpState1 = nts::Tristate::UNDEFINED;
        this->getMap().at(11)->setState(tmpState1);
    }
    if (pin == 11)
        return tmpState1;

    if (isUndefined(this->getMap().at(1)->getComponent()->compute(this->getMap().at(1)->getPin()), this->getMap().at(15)->getComponent()->compute(this->getMap().at(15)->getPin())))
    { //3 Bit Adder
        bool tmp1 = stateToBool(this->getMap().at(4)->getComponent()->compute(this->getMap().at(4)->getPin()));
        bool tmp2 = stateToBool(this->getMap().at(5)->getComponent()->compute(this->getMap().at(5)->getPin()));
        bool car = stateToBool(carrier);
        tmpState1 = std::get<0>(gate(tmp1, tmp2, car));
        carrier = std::get<1>(gate(tmp1, tmp2, car));
        this->getMap().at(12)->setState(tmpState1);
        this->getMap().at(14)->setState(carrier);
    }
    else
    {
        tmpState1 = nts::Tristate::UNDEFINED;
        this->getMap().at(12)->setState(tmpState1);
    }
    if (pin == 12)
        return tmpState1;

    if (isUndefined(this->getMap().at(1)->getComponent()->compute(this->getMap().at(1)->getPin()), this->getMap().at(15)->getComponent()->compute(this->getMap().at(15)->getPin())))
    { //4 Bit Adder
        bool tmp1 = stateToBool(this->getMap().at(7)->getComponent()->compute(this->getMap().at(7)->getPin()));
        bool tmp2 = stateToBool(this->getMap().at(6)->getComponent()->compute(this->getMap().at(6)->getPin()));
        bool car = stateToBool(carrier);
        tmpState1 = std::get<0>(gate(tmp1, tmp2, car));
        // if (tmp1 && tmp2 && !car) {
        //     tmpState1 = nts::Tristate::TRUE;
        //     car = nts::Tristate::FALSE;
        // }
        carrier = std::get<1>(gate(tmp1, tmp2, car));
        this->getMap().at(13)->setState(tmpState1);
        this->getMap().at(14)->setState(carrier);
    }
    else
    {
        tmpState1 = nts::Tristate::UNDEFINED;
        this->getMap().at(12)->setState(tmpState1);
    }
    if (pin == 13)
        return tmpState1;
    if (pin == 14)
        return carrier;
    return nts::Tristate::UNDEFINED;
}