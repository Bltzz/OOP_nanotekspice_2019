/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4013.hpp
*/

#ifndef COMPONENT4013_HPP
    #define COMPONENT4013_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4013 : public AChipset {
    public:
        Component4013(std::string name);
        ~Component4013();

        nts::Tristate compute(std::size_t pin);

    public:
        nts::Tristate gate(nts::Tristate, nts::Tristate, int);
        nts::Tristate reverse(nts::Tristate);

        nts::Tristate pinO1(int pin);
        nts::Tristate pinO2(int pin);
};

#endif
