/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4040.cpp
*/

#include "Component4040.hpp"
#include "ComponentClock.hpp"
#include <cmath>
#include <iostream>
#include <vector>

Component4040::Component4040(std::string name)
{
    this->name = name;
    this->type = "4040";
    this->numPins = 15;
    this->counter = 0;

    pins[9] = new Pins(Pins::Type::OUTPUT, 9, nts::Tristate::FALSE);   // Q0
    pins[7] = new Pins(Pins::Type::OUTPUT, 7, nts::Tristate::FALSE);   // Q1
    pins[6] = new Pins(Pins::Type::OUTPUT, 6, nts::Tristate::FALSE);   // Q2
    pins[5] = new Pins(Pins::Type::OUTPUT, 5, nts::Tristate::FALSE);   // Q3
    pins[3] = new Pins(Pins::Type::OUTPUT, 3, nts::Tristate::FALSE);   // Q4
    pins[2] = new Pins(Pins::Type::OUTPUT, 2, nts::Tristate::FALSE);   // Q5
    pins[4] = new Pins(Pins::Type::OUTPUT, 4, nts::Tristate::FALSE);   // Q6
    pins[13] = new Pins(Pins::Type::OUTPUT, 13, nts::Tristate::FALSE); // Q7
    pins[12] = new Pins(Pins::Type::OUTPUT, 12, nts::Tristate::FALSE); // Q8
    pins[14] = new Pins(Pins::Type::OUTPUT, 14, nts::Tristate::FALSE); // Q9
    pins[15] = new Pins(Pins::Type::OUTPUT, 15, nts::Tristate::FALSE); // Q10
    pins[1] = new Pins(Pins::Type::OUTPUT, 1, nts::Tristate::FALSE);   // Q11
    pins[10] = new Pins(Pins::Type::CLOCK, 10);                        // clock input 0 to 1 triggered
    pins[11] = new Pins(Pins::Type::INPUT, 11);                        // Master reset
}

Component4040::~Component4040()
{
    for (auto it : getMap())
    {
        delete it.second;
        getMap().erase(it.first);
    }
}

bool Component4040::checkMaster()
{
    if (this->getMap().at(11)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component4040::checkClock()
{
    if (this->getMap().at(10)->getComponent()->compute() == nts::Tristate::FALSE)
    {
        counter = counter + 1;
        return true;
    }
    return false;
}

nts::Tristate Component4040::reverse(nts::Tristate t)
{
    if (t == nts::Tristate::FALSE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}

nts::Tristate Component4040::_computeOnce(std::size_t pin)
{
    std::vector<int> pinOrder = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};
    if (!checkMaster() && checkClock() && pin != 10 && pin != 11)
    {
        for (int i = 0; i < (int)pinOrder.size(); i++)
        {
            for (auto it : getMap())
            {
                if (it.first == pinOrder.at(i))
                {

                    //if (((counter != 0) && ((counter & (counter - 1)) == 0)))// counter % pow(2,i) == 0
                    if ((counter % (int)pow(2.0, i)) == 0)
                    {
                        it.second->setState(reverse(it.second->getState()));
                    }
                }
            }
        }
    }
    return this->getMap().at(pin)->getState();
}

nts::Tristate Component4040::compute(std::size_t pin = 1)
{
    if (pin == 0 || (int)pin > this->numPins || pin == 8)
        throw InvalidArgumentException("Pin is invalid or does not exist", this->getName());

    if (this->checkMaster())
    {
        for (auto tmp : this->getMap())
            if (tmp.second->getType() == Pins::Type::OUTPUT)
                tmp.second->setState(nts::Tristate::FALSE);
        counter = 0;
        return this->getMap().at(pin)->getState();
    }
    if (pin == 9)
        _computeOnce(pin);
    if (pin != 10 && pin != 11)
        return this->getMap().at(pin)->getState();
    return nts::Tristate::UNDEFINED;
}

// #include "ComponentClock.hpp"

// int main(){
//     Component4040 c("test");
//     ComponentClock clk("clk");
//     ComponentInput in("in");
//     in.setValue(false);
//     c.setLink(10, clk, 1);
//     c.setLink(11, in, 1);
//     // c.compute();
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
//     std::cout << c.compute(5) << std::endl;
// }