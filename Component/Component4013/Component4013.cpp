/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4013.cpp
** D-Type-Dual-Flip-Flop
*/

#include "Component4013.hpp"
#include <iostream>

Component4013::Component4013(std::string name)
{
    this->name = name;
    this->type = "4013";
    this->numPins = 13;

    pins[1] = new Pins(Pins::Type::OUTPUT, 1);  // (Q) Output
    pins[2] = new Pins(Pins::Type::OUTPUT, 2);  // (!Q) Output
    pins[3] = new Pins(Pins::Type::CLOCK, 3);   // Clock 1
    pins[4] = new Pins(Pins::Type::INPUT, 4);       // Reset 1
    pins[5] = new Pins(Pins::Type::INPUT, 5);   // Data Input
    pins[6] = new Pins(Pins::Type::INPUT, 6);   // Set 1
    pins[8] = new Pins(Pins::Type::INPUT, 8);   // Set 2
    pins[9] = new Pins(Pins::Type::INPUT, 9);   // Data2
    pins[10] = new Pins(Pins::Type::OUTPUT, 10);    // Reset 2
    pins[11] = new Pins(Pins::Type::CLOCK, 11); // Clock 2
    pins[12] = new Pins(Pins::Type::INPUT, 12); // (!Q2) Output
    pins[13] = new Pins(Pins::Type::INPUT, 13); // (Q2) Output
}

Component4013::~Component4013() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

nts::Tristate Component4013::reverse(nts::Tristate t)
{
    if (t == nts::Tristate::FALSE)
        return nts::Tristate::TRUE;
    else if (t == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate Component4013::gate(nts::Tristate t1, nts::Tristate clock, int pin)
{ //always compute Q
    if (clock == nts::Tristate::FALSE && (pin == 2 || pin == 1))
        return this->getMap().at(1)->getComponent()->getMap().at(1)->getState();
    else if (clock == nts::Tristate::FALSE && (pin == 12 || pin == 13))
        return this->getMap().at(13)->getComponent()->getMap().at(1)->getState();
    else if (t1 == nts::Tristate::FALSE && clock == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    else if (t1 == nts::Tristate::TRUE && clock == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate Component4013::pinO1(int pin)
{
    nts::Tristate outputState;
    nts::Tristate clock = this->pins.at(3)->getComponent()->compute(pins.at(3)->getPin());
    nts::Tristate reset = this->pins.at(4)->getComponent()->compute(pins.at(4)->getPin());
    nts::Tristate input = this->pins.at(5)->getComponent()->compute(pins.at(5)->getPin());
    nts::Tristate set = this->pins.at(6)->getComponent()->compute(pins.at(6)->getPin());

    if (reset == nts::Tristate::FALSE && set == nts::Tristate::TRUE)
        outputState = nts::Tristate::TRUE;
    else if (reset == nts::Tristate::TRUE && set == nts::Tristate::FALSE)
        outputState = nts::Tristate::FALSE;
    else if (reset == nts::Tristate::TRUE && set == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    else if (reset == nts::Tristate::FALSE && set == nts::Tristate::FALSE)
        outputState = gate(input, clock, pin);

    if (pin == 1)
        return outputState;
    return reverse(outputState);
}

nts::Tristate Component4013::pinO2(int pin)
{
    nts::Tristate outputState;
    nts::Tristate set = this->pins.at(8)->getComponent()->compute(pins.at(8)->getPin());
    nts::Tristate input = this->pins.at(9)->getComponent()->compute(pins.at(9)->getPin());
    nts::Tristate reset = this->pins.at(10)->getComponent()->compute(pins.at(10)->getPin());
    nts::Tristate clock = this->pins.at(11)->getComponent()->compute(pins.at(11)->getPin());

    if (reset == nts::Tristate::FALSE && set == nts::Tristate::TRUE)
        outputState = nts::Tristate::TRUE;
    else if (reset == nts::Tristate::TRUE && set == nts::Tristate::FALSE)
        outputState = nts::Tristate::FALSE;
    else if (reset == nts::Tristate::TRUE && set == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    else if (reset == nts::Tristate::FALSE && set == nts::Tristate::FALSE)
        outputState = gate(input, clock, pin);

    if (pin == 13)
        return outputState;
    return reverse(outputState);
}

nts::Tristate Component4013::compute(std::size_t pin = 1)
{
    if (pin == 1 || pin == 2)
        return pinO1(pin);
    else if (pin == 12 || pin == 13)
        return pinO2(pin);
    return this->pins.at(pin)->getState();
}