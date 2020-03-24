/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentTrue.hpp
*/

#ifndef COMPONENTTRUE_HPP
    #define COMPONENTTRUE_HPP

#include "AChipset.hpp"
#include <string>
#include <map>

class ComponentTrue : public AChipset {
    public:
        explicit ComponentTrue(std::string const name);
        ~ComponentTrue();

        nts::Tristate compute(std::size_t pin);
};

#endif
