/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4081.cpp
*/

#include "Component4081.hpp"
#include <iostream>

Component4081::Component4081(std::string const name)
{
    this->name = name;
    this->type = "4081";
    this->numPins = 13;

    pins[1] = new Pins(Pins::Type::INPUT, 1);
    pins[2] = new Pins(Pins::Type::INPUT, 2);
    pins[3] = new Pins(Pins::Type::OUTPUT, 3);
    pins[4] = new Pins(Pins::Type::OUTPUT, 4);
    pins[5] = new Pins(Pins::Type::INPUT, 5);
    pins[6] = new Pins(Pins::Type::INPUT, 6);
    pins[8] = new Pins(Pins::Type::INPUT, 8);
    pins[9] = new Pins(Pins::Type::INPUT, 9);
    pins[10] = new Pins(Pins::Type::OUTPUT, 10);
    pins[11] = new Pins(Pins::Type::OUTPUT, 11);
    pins[12] = new Pins(Pins::Type::INPUT, 12);
    pins[13] = new Pins(Pins::Type::INPUT, 13);
}

Component4081::~Component4081() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

nts::Tristate Component4081::and_gate(nts::Tristate t1, nts::Tristate t2)
{
    if (t1 == nts::Tristate::TRUE && t2 == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    else if ((t1 == nts::Tristate::TRUE && t2 == nts::Tristate::UNDEFINED) || (t1 == nts::Tristate::UNDEFINED && t2 == nts::Tristate::TRUE))
        return nts::Tristate::UNDEFINED;
    return nts::Tristate::FALSE;
}

nts::Tristate Component4081::pin3()
{
    nts::Tristate var1 = this->pins.at(1)->getComponent()->compute(pins.at(1)->getPin());
    nts::Tristate var2 = this->pins.at(2)->getComponent()->compute(pins.at(2)->getPin());

    return and_gate(var1, var2);
}

nts::Tristate Component4081::pin4()
{
    nts::Tristate var1 = this->pins.at(5)->getComponent()->compute(pins.at(5)->getPin());
    nts::Tristate var2 = this->pins.at(6)->getComponent()->compute(pins.at(6)->getPin());

    return and_gate(var1, var2);
}

nts::Tristate Component4081::pin10()
{
    nts::Tristate var1 = this->pins.at(8)->getComponent()->compute(pins.at(8)->getPin());
    nts::Tristate var2 = this->pins.at(9)->getComponent()->compute(pins.at(9)->getPin());

    return and_gate(var1, var2);
}

nts::Tristate Component4081::pin11()
{
    nts::Tristate var1 = this->pins.at(12)->getComponent()->compute(pins.at(12)->getPin());
    nts::Tristate var2 = this->pins.at(13)->getComponent()->compute(pins.at(13)->getPin());

    return and_gate(var1, var2);
}

nts::Tristate Component4081::compute(std::size_t pin = 1)
{
    if (pin == 3)
        return pin3();
    else if (pin == 4)
        return pin4();
    else if (pin == 10)
        return pin10();
    else if (pin == 11)
        return pin11();
    return this->pins[pin]->getState();
}