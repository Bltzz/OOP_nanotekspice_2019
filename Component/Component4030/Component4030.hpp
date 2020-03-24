/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4030.hpp
*/

#ifndef COMPONENT4030_HPP
    #define COMPONENT4030_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4030 : public AChipset {
    public:
        explicit Component4030(std::string const name);
        ~Component4030();

        nts::Tristate compute(std::size_t pin);

    public:
        nts::Tristate xor_gate(nts::Tristate, nts::Tristate);
        nts::Tristate pin3();
        nts::Tristate pin4();
        nts::Tristate pin10();
        nts::Tristate pin11();
};

#endif
