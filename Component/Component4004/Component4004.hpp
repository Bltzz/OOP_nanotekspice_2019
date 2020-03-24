/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4004.hpp
*/

#ifndef COMPONENT4004_HPP
    #define COMPONENT4004_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4004 : public AChipset {
    public:
        Component4004(std::string name);
        ~Component4004();

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
