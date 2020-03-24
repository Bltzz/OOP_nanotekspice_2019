/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component2716.cpp
*/

#include "Component2716.hpp"
#include "ComponentClock.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

Component2716::Component2716(std::string name)
{
    this->type = "2716";
    this->numPins = 23;
    if (std::count(name.begin(), name.end(), '(') != 1 ||
    std::count(name.begin(), name.end(), ')') != 1 ||
    name.find('(') > name.find(')') ||
    name.find(')') != name.size() - 1)
        throw DoesNotExistException("The syntax is invalid", "Line : " + name);
    this->name = name.substr(0, name.find('('));
    std::string path = name.substr(name.find('(') + 1, std::string::npos);
    path = path.substr(0, path.find(')'));
    if (path == "")
        throw DoesNotExistException("The syntax is invalid", "Line : " + name);
    //####################################################################################################################
    // init
    std::ifstream binFile;
    binFile.open(path, std::ios::binary); // just for test purposes, factory has to forward the given File Path.
                                                                  // check for file.open() needed-> later ;)
    if (binFile.fail())
        throw DoesNotExistException("Invalid filepath", "Path : " + path);
    binFile.seekg(0, std::ios::beg);
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 128; j++)
            for (int k = 0; k < 8; k++)
            {
                try
                {
                    char *c = new char[1]; // because!
                    binFile.read(c, 1);
                    this->matrix[i][j][k] = c;
                    delete[] c;
                }
                catch (std::ios_base::iostate &e)
                {
                    this->matrix[i][j][k] = 0;
                }
            }
    binFile.close();
    //####################################################################################################################
    pins[8] = new Pins(Pins::Type::INPUT, 8);    // A0
    pins[7] = new Pins(Pins::Type::INPUT, 7);    // A1
    pins[6] = new Pins(Pins::Type::INPUT, 6);    // A2
    pins[5] = new Pins(Pins::Type::INPUT, 5);    // A3
    pins[4] = new Pins(Pins::Type::INPUT, 4);    // A4
    pins[3] = new Pins(Pins::Type::INPUT, 3);    // A5
    pins[2] = new Pins(Pins::Type::INPUT, 2);    // A6
    pins[1] = new Pins(Pins::Type::INPUT, 1);    // A7
    pins[23] = new Pins(Pins::Type::INPUT, 23);  // A8
    pins[22] = new Pins(Pins::Type::INPUT, 22);  // A9
    pins[19] = new Pins(Pins::Type::INPUT, 19);  // A10
    pins[9] = new Pins(Pins::Type::OUTPUT, 9);   // DQ0
    pins[10] = new Pins(Pins::Type::OUTPUT, 10); // DQ1
    pins[11] = new Pins(Pins::Type::OUTPUT, 11); // DQ2
    pins[13] = new Pins(Pins::Type::OUTPUT, 13); // DQ3
    pins[14] = new Pins(Pins::Type::OUTPUT, 14); // DQ4
    pins[15] = new Pins(Pins::Type::OUTPUT, 15); // DQ5
    pins[16] = new Pins(Pins::Type::OUTPUT, 16); // DQ6
    pins[17] = new Pins(Pins::Type::OUTPUT, 17); // DQ7
    pins[18] = new Pins(Pins::Type::INPUT, 18);  // invers CE
    pins[20] = new Pins(Pins::Type::INPUT, 20);  // invers OE
    pins[21] = new Pins(Pins::Type::INPUT, 21);  // invers OE
}

Component2716::~Component2716()
{
    for (auto it : getMap())
    {
        delete it.second;
        getMap().erase(it.first);
    }
}

bool Component2716::checkMaster()
{
    if (this->getMap().at(18)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

bool Component2716::checkOutputEnable()
{
    if (this->getMap().at(20)->getComponent()->compute() == nts::Tristate::TRUE)
        return true;
    return false;
}

nts::Tristate Component2716::reverse(nts::Tristate t)
{
    if (t == nts::Tristate::FALSE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}

bool Component2716::stateToBool(nts::Tristate t)
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

nts::Tristate Component2716::boolToState(bool tmp = false)
{
    if (tmp == true)
        return nts::Tristate::TRUE;
    else
        return nts::Tristate::FALSE;
}
unsigned int Component2716::convertBinToDec(bool decider)
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

nts::Tristate Component2716::compute(std::size_t pin = 1)
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