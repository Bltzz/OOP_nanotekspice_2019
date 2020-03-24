/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4069.hpp
*/

#ifndef COMPONENT4069_HPP
    #define COMPONENT4069_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4069 : public AChipset {
    public:
        explicit Component4069(std::string const name);
        ~Component4069();

        nts::Tristate compute(std::size_t pin);

    public:
        nts::Tristate inverse_gate(nts::Tristate var1);
        nts::Tristate pin2();
        nts::Tristate pin4();
        nts::Tristate pin6();
        nts::Tristate pin8();
        nts::Tristate pin10();
        nts::Tristate pin12();
};

#endif
