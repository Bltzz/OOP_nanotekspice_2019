/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"
#include "DoesNotExistException.hpp"
#include <iostream>

ComponentClock::ComponentClock(std::string const name) : ComponentInput(name)
{
    this->name = name;
    this->type = "clock";
    this->numPins = 1;

    pins[1] = new Pins(Pins::Type::OUTPUT, 1);

}

ComponentClock::~ComponentClock() {}

nts::Tristate ComponentClock::compute(std::size_t pin = 1)
{
    if (pin == 1)
    {
        if (this->getMap().at(pin)->getState() == nts::Tristate::TRUE)
        {
            //this->getMap()[pin]->setState(nts::Tristate::FALSE);
            return nts::Tristate::TRUE;
        }
        else
        {
            //this->getMap()[pin]->setState(nts::Tristate::TRUE);
            return nts::Tristate::FALSE;
        }
    }
    else
        throw PinDoesNotExistError("Pin Does not exist for CLOCK-Component (only Pin 1 possible)", this->getName());
}

// int main(){
//     ComponentClock *c1 = new ComponentClock();
//     ComponentClock *c2 = new ComponentClock();
//     c1->setLink(2, *c2, 4);
//     std::cout << c1->compute(4);
//     delete c1;
//     delete c2;

//     return 0;
// }