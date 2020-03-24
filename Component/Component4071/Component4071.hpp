/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4071.hpp
*/

#ifndef COMPONENT4071_HPP
    #define COMPONENT4071_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4071 : public AChipset
{
public:
    explicit Component4071(std::string const name);
    ~Component4071();

    nts::Tristate compute(std::size_t pin);

public:
    nts::Tristate or_gate(nts::Tristate, nts::Tristate);
    nts::Tristate pin3();
    nts::Tristate pin4();
    nts::Tristate pin10();
    nts::Tristate pin11();
};

#endif
