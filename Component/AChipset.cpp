/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** AChipset.cpp
*/

#include "AChipset.hpp"
#include "DoesNotExistException.hpp"
#include "NotFoundException.hpp"
#include <iostream>

void AChipset::dump() const {
    std::cout << "Type of Component: " << this->getType() <<std::endl;
    std::cout << "User given Name of Component: " << this->getName() << "\n" << std::endl;
    std::cout << "Value of Output Pins: \n" <<std::endl;
    for (auto &tmp : this->getMap())
        if (tmp.second->getType() == Pins::Type::OUTPUT)
            std::cout << "Pin "<< tmp.first << ": " << tmp.second->getComponent()->getMap().at(tmp.second->getPin())->getState() << std::endl;
}

static bool areCompatible(Pins::Type thisType, Pins::Type otherType)
{
    if ((thisType == Pins::Type::INPUT && otherType == Pins::Type::OUTPUT) ||
    (thisType == Pins::Type::CLOCK && otherType == Pins::Type::OUTPUT) ||
    (thisType == Pins::Type::OUTPUT && otherType == Pins::Type::CLOCK) ||
    (thisType == Pins::Type::OUTPUT && otherType == Pins::Type::INPUT) ||
    (thisType == Pins::Type::CLOCK && otherType == Pins::Type::OUTPUT))
        return true;
    return false;
}

void AChipset::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (this->getMap().find(pin) == this->getMap().end() || other.getMap().find(otherPin) == other.getMap().end())
        throw PinDoesNotExistError();
    Pins::Type thisType = this->getMap()[pin]->getType();
    Pins::Type otherType = other.getMap()[otherPin]->getType();

    if (areCompatible(thisType, otherType))
    {
        this->pins[pin]->setComponent(other);
        this->pins[pin]->setPin(otherPin);
        other.getMap()[otherPin]->setComponent(*this);
        other.getMap()[otherPin]->setPin(pin);
    }
    else
        throw PinDoesNotExistError("Invalid Pin or Pin-type. Not possible to link these two Pins.", this->getName());
}