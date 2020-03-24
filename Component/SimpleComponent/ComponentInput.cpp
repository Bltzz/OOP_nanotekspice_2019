/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"
#include "DoesNotExistException.hpp"
#include <iostream>

ComponentInput::ComponentInput(std::string const name)
{
    this->name = name;
    this->type = "input";
    this->numPins = 1;
    this->_is_set = false;
    pins[1] = new Pins(Pins::Type::OUTPUT, 1);

}

ComponentInput::~ComponentInput() {
    // for (auto it : getMap()){
    //     delete it.second;
    //     getMap().erase(it.first);
    // }
}

nts::Tristate ComponentInput::compute(std::size_t pin = 1)
{
    if (pin == 1)
        return (this->getMap().at(pin)->getState());
    else
        throw PinDoesNotExistError("Pin Does not exist for TRUE-Component (only Pin 1 possible)", this->getName());
}

void ComponentInput::dump() const
{
    std::cout << "< Type of Component: " << this->getType() <<std::endl;
    std::cout << "< User given Name of Component: " << this->getName() << "\n" << std::endl;
    std::cout << "< Value of Output Pins: \n" <<std::endl;
    std::cout << "< Value of Pin: " << this->getMap().at(1)->getState() << std::endl;
}

 void ComponentInput::setValue(bool b) {
    this->input_value = b;
    if (b)
        this->pins.at(1)->setState(nts::Tristate::TRUE);
    else
        this->pins.at(1)->setState(nts::Tristate::FALSE);
}