/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4011.hpp
*/

#ifndef COMPONENT4011_HPP
    #define COMPONENT4011_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4011 : public AChipset {
    public:
        explicit Component4011(std::string name);
        ~Component4011();

        nts::Tristate compute(std::size_t pin);
    public:
        nts::Tristate nand_gate(nts::Tristate, nts::Tristate);
        nts::Tristate pin3();
        nts::Tristate pin4();
        nts::Tristate pin10();
        nts::Tristate pin11();
};

#endif
