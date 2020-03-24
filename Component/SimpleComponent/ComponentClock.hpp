/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentClock.hpp
*/

#ifndef COMPONENTCLOCK_HPP
    #define COMPONENTCLOCK_HPP

#include "ComponentInput.hpp"
#include <string>
#include <map>

class ComponentClock : public ComponentInput {
    public:
        explicit ComponentClock(std::string const name);
        ~ComponentClock();

        nts::Tristate compute(std::size_t pin);
};

#endif
