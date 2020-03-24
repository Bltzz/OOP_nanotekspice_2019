/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentOutput.cpp
*/

#include "ComponentOutput.hpp"
#include "DoesNotExistException.hpp"
#include <iostream>

ComponentOutput::ComponentOutput(std::string name)
{
    this->name = name;
    this->type = "output";
    this->numPins = 1;
    pins[1] = new Pins(Pins::Type::INPUT, 1);
}

ComponentOutput::~ComponentOutput() {
    // for (auto it : getMap()){
    //     delete it.second;
    //     getMap().erase(it.first);
    // }
}

nts::Tristate ComponentOutput::compute(std::size_t pin = 1)
{
    if (pin == 1)
    {
        this->setValue(this->getMap().at(pin)->getComponent()->compute(this->getMap()[1]->getPin()));
        return this->getValue();
        //return (this->getMap()[1]->getComponent()->compute(this->getMap()[1]->getPin()));
    }
    else
        throw PinDoesNotExistError("Pin Does not exist for Output-Component (only Pin 1 possible)", this->getType());
}

bool ComponentOutput::operator<(const ComponentOutput &other) const
{
    return (this->getName() < other.getName());
}

ComponentOutput &ComponentOutput::operator=(const ComponentOutput &other)
{
    this->name = other.getName();
    this->pins[1] = other.getMap()[1];
    this->output_value = other.getValue();
    return *this;
}

void ComponentOutput::setValue(nts::Tristate b)
{
    this->output_value = b;
    this->pins[1]->setState(b);
}

void ComponentOutput::dump(){
    std::cout << "< Type of Component: " << this->getType() <<std::endl;
    std::cout << "< User given Name of Component: " << this->getName() << std::endl;
    std::cout << "< Value of Pin: ";
    std::cout << this->getMap()[1]->getState() << std::endl;
}