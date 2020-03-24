/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4017.hpp
*/

#ifndef COMPONENT4017_HPP
    #define COMPONENT4017_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4017 : public AChipset {
    public:
        Component4017(std::string name);
        ~Component4017();

        nts::Tristate compute(std::size_t pin);
        nts::Tristate _computeOnce(std::size_t pin);

    public:
        bool stateToBool(nts::Tristate);
        bool isUndefined(nts::Tristate, nts::Tristate);
        bool checkMaster();
        bool checkClockHL();
        bool checkClockLH();
};

#endif
