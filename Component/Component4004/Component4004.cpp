/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4004.cpp
*/

#include "Component4004.hpp"
#include "ComponentClock.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

Component4004::Component4004(std::string name)
{
    this->name = name;
    this->type = "4004";
    this->numPins = 23;

    pins[1] = new Pins(Pins::Type::INPUT, 1);    // Data Bus D0
    pins[2] = new Pins(Pins::Type::INPUT, 2);    // Data Bus D1
    pins[3] = new Pins(Pins::Type::INPUT, 3);    // Data Bus D2
    pins[4] = new Pins(Pins::Type::INPUT, 4);    // Data Bus D3
    pins[6] = new Pins(Pins::Type::CLOCK, 6);    // Clock Phase1
    pins[7] = new Pins(Pins::Type::CLOCK, 7);    // Clock Phase2
    pins[8] = new Pins(Pins::Type::OUTPUT, 8);   // Sync Output
    pins[9] = new Pins(Pins::Type::INPUT, 9);    // Reset
    pins[10] = new Pins(Pins::Type::INPUT, 10);  // Test
    pins[11] = new Pins(Pins::Type::INPUT, 11);  // CM-ROM Memory Control Outputs
    pins[13] = new Pins(Pins::Type::INPUT, 13);  // CM-RAM 3
    pins[14] = new Pins(Pins::Type::OUTPUT, 14); // CM-RAM 2
    pins[15] = new Pins(Pins::Type::OUTPUT, 15); // CM-RAM 1
    pins[16] = new Pins(Pins::Type::OUTPUT, 16); // CM-RAM 0
                                                 // 5 and 12 VSS/ VDD-> not relavant
}

Component4004::~Component4004()
{
    for (auto it : getMap())
    {
        delete it.second;
        getMap().erase(it.first);
    }
}

bool Component4004::checkMaster()
{
    if (this->getMap().at(18)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component4004::checkOutputEnable()
{
    if (this->getMap().at(20)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

nts::Tristate Component4004::reverse(nts::Tristate t)
{
    if (t == nts::Tristate::FALSE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}

bool Component4004::stateToBool(nts::Tristate t)
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

nts::Tristate Component4004::boolToState(bool tmp = false)
{
    if (tmp == true)
        return nts::Tristate::TRUE;
    else
        return nts::Tristate::FALSE;
}
unsigned int Component4004::convertBinToDec(bool decider)
{
    int pos1 = stateToBool(this->getMap().at(8)->getComponent()->compute());
    int pos2 = stateToBool(this->getMap().at(7)->getComponent()->compute());
    int pos3 = stateToBool(this->getMap().at(6)->getComponent()->compute());
    int pos4 = stateToBool(this->getMap().at(5)->getComponent()->compute());
    int pos5 = 0, pos6 = 0, pos7 = 0;
    if (decider)
    {
        pos1 = stateToBool(this->getMap().at(4)->getComponent()->compute());
        pos2 = stateToBool(this->getMap().at(3)->getComponent()->compute());
        pos3 = stateToBool(this->getMap().at(2)->getComponent()->compute());
        pos4 = stateToBool(this->getMap().at(1)->getComponent()->compute());
        pos5 = stateToBool(this->getMap().at(23)->getComponent()->compute());
        pos6 = stateToBool(this->getMap().at(22)->getComponent()->compute());
        pos7 = stateToBool(this->getMap().at(19)->getComponent()->compute());
    }

    unsigned int dec = 0;
    unsigned int remainder;
    int i = 0;

    unsigned int res = (1000000 * pos7 + 100000 * pos6 + 10000 * pos5 + 1000 * pos4 + 100 * pos3 + 10 * pos2 + pos1);
    while (res)
    {
        remainder = res % 10;
        res /= 10;
        dec += remainder * pow(2.0, i);
        ++i;
    }
    return dec;
}

nts::Tristate Component4004::compute(std::size_t pin = 1)
{
    std::vector<int> pinOrder = {9, 10, 11, 13, 14, 15, 16, 17};

    if (!checkMaster() && !checkOutputEnable()) // MODE: READ
    {
        for (int i = 0; i < 8; i++)
            getMap().at(pinOrder.at(i))->setState(boolToState(matrix[convertBinToDec(false)][convertBinToDec(true)][i])); // map.at(pin)->setState(matrix[a][b][c])
    }
    if (checkMaster() && checkOutputEnable()) // MODE: PROGRAM
    {
        for (int i = 0; i < 8; i++)
            matrix[convertBinToDec(false)][convertBinToDec(true)][i] = stateToBool(getMap().at(pinOrder.at(i))->getState());
    }
    return this->getMap().at(pin)->getState();
}