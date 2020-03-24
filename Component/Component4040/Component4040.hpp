/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4040.hpp
*/

#ifndef COMPONENT4040_HPP
    #define COMPONENT4040_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4040 : public AChipset {
    public:
        Component4040(std::string name);
        ~Component4040();

        nts::Tristate compute(std::size_t pin);
        nts::Tristate _computeOnce(std::size_t);

    public:
        bool checkMaster();
        bool checkClock();
        nts::Tristate reverse(nts::Tristate);

    private:
        int counter;
};

#endif
