/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4001.hpp
*/

#ifndef COMPONENT4001_HPP
    #define COMPONENT4001_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4001 : public AChipset {
    public:
        Component4001(std::string name);
        ~Component4001();

        nts::Tristate compute(std::size_t pin);

    public:
        nts::Tristate nor_gate(nts::Tristate, nts::Tristate);
        nts::Tristate pin3();
        nts::Tristate pin4();
        nts::Tristate pin10();
        nts::Tristate pin11();
};

#endif
