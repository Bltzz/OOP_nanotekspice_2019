/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4069.cpp
*/

#include "Component4069.hpp"
#include <iostream>

Component4069::Component4069(std::string const name)
{
    this->name = name;
    this->type = "4069";
    this->numPins = 13;

    pins[1] = new Pins(Pins::Type::INPUT, 1);
    pins[2] = new Pins(Pins::Type::OUTPUT, 2);
    pins[3] = new Pins(Pins::Type::INPUT, 3);
    pins[4] = new Pins(Pins::Type::OUTPUT, 4);
    pins[5] = new Pins(Pins::Type::INPUT, 5);
    pins[6] = new Pins(Pins::Type::OUTPUT, 6);
    pins[8] = new Pins(Pins::Type::OUTPUT, 8);
    pins[9] = new Pins(Pins::Type::INPUT, 9);
    pins[10] = new Pins(Pins::Type::OUTPUT, 10);
    pins[11] = new Pins(Pins::Type::INPUT, 11);
    pins[12] = new Pins(Pins::Type::OUTPUT, 12);
    pins[13] = new Pins(Pins::Type::INPUT, 13);
}

Component4069::~Component4069() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

nts::Tristate Component4069::inverse_gate(nts::Tristate var1)
{
    if (var1 == nts::Tristate::TRUE)
    {
        return nts::Tristate::FALSE;
    }
    else if (var1 == nts::Tristate::FALSE)
        return nts::Tristate::TRUE;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate Component4069::pin2()
{
    nts::Tristate var1 = this->pins.at(1)->getComponent()->compute(pins.at(1)->getPin());

    return inverse_gate(var1);
}

nts::Tristate Component4069::pin4()
{
    nts::Tristate var1 = this->pins.at(3)->getComponent()->compute(pins.at(3)->getPin());

    return inverse_gate(var1);
}

nts::Tristate Component4069::pin6()
{
    nts::Tristate var1 = this->pins.at(5)->getComponent()->compute(pins.at(5)->getPin());

    return inverse_gate(var1);
}
nts::Tristate Component4069::pin8()
{
    nts::Tristate var1 = this->pins.at(9)->getComponent()->compute(pins.at(9)->getPin());

    return inverse_gate(var1);
}
nts::Tristate Component4069::pin10()
{
    nts::Tristate var1 = this->pins.at(11)->getComponent()->compute(pins.at(11)->getPin());

    return inverse_gate(var1);
}

nts::Tristate Component4069::pin12()
{
    nts::Tristate var1 = this->pins.at(13)->getComponent()->compute(pins.at(13)->getPin());

    return inverse_gate(var1);
}

nts::Tristate Component4069::compute(std::size_t pin = 1)
{
    switch (pin)
    {
    case 2:
        return pin2();
    case 4:
        return pin4();
    case 6:
        return pin6();
    case 8:
        return pin8();
    case 10:
        return pin10();
    case 12:
        return pin12();
    default:
        return nts::Tristate::UNDEFINED;
    }
}