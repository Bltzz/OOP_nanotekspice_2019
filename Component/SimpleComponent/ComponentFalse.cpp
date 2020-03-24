/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentFalse.cpp
*/

#include "ComponentFalse.hpp"
#include "DoesNotExistException.hpp"
#include <iostream>

ComponentFalse::ComponentFalse(std::string const name)
{
    this->name = name;
    this->type = "false";
    this->numPins = 1;

    pins[1] = new Pins(Pins::Type::OUTPUT, 1, nts::Tristate::FALSE);
}

ComponentFalse::~ComponentFalse() {
    // for (auto it : getMap()){
    //     delete it.second;
    //     getMap().erase(it.first);
    // }
}

nts::Tristate ComponentFalse::compute(std::size_t pin = 1)
{
    if (pin == 1)
        return nts::Tristate::FALSE;
    else
        throw PinDoesNotExistError("Pin Does not exist for FALSE-Component (only Pin 1 possible)", this->getName());
}