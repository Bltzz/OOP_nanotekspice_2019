/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4514.hpp
*/

#ifndef COMPONENT4514_HPP
    #define COMPONENT4514_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4514 : public AChipset {
    public:
        Component4514(std::string name);
        ~Component4514();

        nts::Tristate compute(std::size_t pin);

    public:
        bool checkMaster();
        bool checkStrobe();
        nts::Tristate reverse(nts::Tristate);
        bool stateToBool(nts::Tristate);
        unsigned int convertBinToDec();
};

#endif
