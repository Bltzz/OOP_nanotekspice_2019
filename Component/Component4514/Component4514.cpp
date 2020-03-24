/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4514.cpp
*/

#include "Component4514.hpp"
#include "ComponentClock.hpp"
#include <cmath>
#include <iostream>
#include <vector>

Component4514::Component4514(std::string name)
{
    this->name = name;
    this->type = "4514";
    this->numPins = 23;

    pins[1] = new Pins(Pins::Type::INPUT, 1);   // Strobe
    pins[2] = new Pins(Pins::Type::INPUT, 2);   // Input A
    pins[3] = new Pins(Pins::Type::INPUT, 3);   // Input B
    pins[21] = new Pins(Pins::Type::INPUT, 21); // Input C
    pins[22] = new Pins(Pins::Type::INPUT, 22); // Input D
    pins[23] = new Pins(Pins::Type::INPUT, 23); // INHIBIT

    pins[11] = new Pins(Pins::Type::OUTPUT, 11, nts::Tristate::FALSE); // S0
    pins[9] = new Pins(Pins::Type::OUTPUT, 9, nts::Tristate::FALSE);   // S1
    pins[10] = new Pins(Pins::Type::OUTPUT, 10, nts::Tristate::FALSE); // S2
    pins[8] = new Pins(Pins::Type::OUTPUT, 8, nts::Tristate::FALSE);   // S3
    pins[7] = new Pins(Pins::Type::OUTPUT, 7, nts::Tristate::FALSE);   // S4
    pins[6] = new Pins(Pins::Type::OUTPUT, 6, nts::Tristate::FALSE);   // S5
    pins[5] = new Pins(Pins::Type::OUTPUT, 5, nts::Tristate::FALSE);   // S6
    pins[4] = new Pins(Pins::Type::OUTPUT, 4, nts::Tristate::FALSE);   // S7
    pins[18] = new Pins(Pins::Type::OUTPUT, 18, nts::Tristate::FALSE); // S8
    pins[17] = new Pins(Pins::Type::OUTPUT, 17, nts::Tristate::FALSE); // S9
    pins[20] = new Pins(Pins::Type::OUTPUT, 20, nts::Tristate::FALSE); // S10
    pins[19] = new Pins(Pins::Type::OUTPUT, 19, nts::Tristate::FALSE); // S11
    pins[14] = new Pins(Pins::Type::OUTPUT, 14, nts::Tristate::FALSE); // S12
    pins[13] = new Pins(Pins::Type::OUTPUT, 13, nts::Tristate::FALSE); // S13
    pins[16] = new Pins(Pins::Type::OUTPUT, 16, nts::Tristate::FALSE); // S14
    pins[15] = new Pins(Pins::Type::OUTPUT, 15, nts::Tristate::FALSE); // S15
}

Component4514::~Component4514() {
    for (auto it : getMap()){
        delete it.second;
        getMap().erase(it.first);
    }
}

bool Component4514::checkMaster()
{
    if (this->getMap().at(23)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component4514::checkStrobe()
{
    if (this->getMap().at(1)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

nts::Tristate Component4514::reverse(nts::Tristate t)
{
    if (t == nts::Tristate::FALSE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}

bool Component4514::stateToBool(nts::Tristate t)
{
    switch (t)
    {
    case nts::Tristate::TRUE:
        return true;
    case nts::Tristate::FALSE:
        return false;
    default:
        return false;
        break;
    }
}

unsigned int Component4514::convertBinToDec()
{
    int posD = stateToBool(this->getMap().at(22)->getComponent()->compute());
    int posC = stateToBool(this->getMap().at(21)->getComponent()->compute());
    int posB = stateToBool(this->getMap().at(3)->getComponent()->compute());
    int posA = stateToBool(this->getMap().at(2)->getComponent()->compute());
    unsigned int dec = 0;
    unsigned int remainder;
    int i = 0;

    unsigned int res = (1000 * posD + 100 * posC + 10 * posB + posA);
    while (res)
    {
        remainder = res % 10;
        res /= 10;
        dec += remainder * pow(2.0, i);
        ++i;
    }
    return dec;
}

nts::Tristate Component4514::compute(std::size_t pin = 1)
{
    std::vector<int> pinOrder = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};
    unsigned int tmp = convertBinToDec();

    if (pin == 0 || (int)pin > this->numPins || pin == 12)
        throw InvalidArgumentException("Pin is invalid or does not exist", this->getName());
    if (this->getMap().at(pin)->getType() != Pins::Type::OUTPUT)
        return nts::Tristate::UNDEFINED;

    if (this->checkMaster())
    {
        for (auto tmp : this->getMap())
            if (tmp.second->getType() == Pins::Type::OUTPUT)
                tmp.second->setState(nts::Tristate::FALSE);
        return this->getMap().at(pin)->getState();
    }
    if (!checkStrobe())
        return this->getMap().at(pin)->getState();

    for (auto tmp : this->getMap())
            if (tmp.second->getType() == Pins::Type::OUTPUT)
                tmp.second->setState(nts::Tristate::FALSE);

    this->getMap().at(pinOrder.at(tmp))->setState(nts::Tristate::TRUE);

    return this->getMap().at(pin)->getState();
}