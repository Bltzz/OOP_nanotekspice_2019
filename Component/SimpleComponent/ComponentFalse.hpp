/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentFalse.hpp
*/

#ifndef COMPONENTFALSE_HPP
    #define COMPONENTFALSE_HPP

#include "AChipset.hpp"
#include <string>
#include <map>

class ComponentFalse : public AChipset {
    public:
        explicit ComponentFalse(std::string const name);
        ~ComponentFalse();

        nts::Tristate compute(std::size_t pin);
};

#endif
