/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4081.hpp
*/

#ifndef COMPONENT4081_HPP
    #define COMPONENT4081_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4081 : public AChipset {
    public:
        explicit Component4081(std::string const name);
        ~Component4081();

        nts::Tristate compute(std::size_t pin);

    public:
        nts::Tristate and_gate(nts::Tristate, nts::Tristate);
        nts::Tristate pin3();
        nts::Tristate pin4();
        nts::Tristate pin10();
        nts::Tristate pin11();
};

#endif
