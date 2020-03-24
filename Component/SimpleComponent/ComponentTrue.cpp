/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentTrue.cpp
*/

#include "ComponentTrue.hpp"
#include "DoesNotExistException.hpp"
#include <iostream>

ComponentTrue::ComponentTrue(std::string const name)
{
    this->name = name;
    this->type = "true";
    this->numPins = 1;

    pins[1] = new Pins(Pins::Type::OUTPUT, 1, nts::Tristate::TRUE);
}

ComponentTrue::~ComponentTrue() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

nts::Tristate ComponentTrue::compute(std::size_t pin = 1)
{
    if (pin == 1)
        return nts::Tristate::TRUE;
    else
        throw PinDoesNotExistError("Pin Does not exist for TRUE-Component (only Pin 1 possible)", this->getName());
}