/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component2716.hpp
*/

#ifndef COMPONENT2716_HPP
    #define COMPONENT2716_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component2716 : public AChipset {
    public:
        Component2716(std::string name);
        ~Component2716();

        nts::Tristate compute(std::size_t pin);

    public:
        bool checkMaster();
        bool checkOutputEnable();
        nts::Tristate reverse(nts::Tristate);
        bool stateToBool(nts::Tristate);
        nts::Tristate boolToState(bool);
        unsigned int convertBinToDec(bool);

    private:
        bool matrix[16][128][8];
};

#endif
