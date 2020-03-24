/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4094.hpp
*/

#ifndef COMPONENT4094_HPP
    #define COMPONENT4094_HPP

#include "AChipset.hpp"
#include <map>
#include <string>
#include <vector>

class Component4094 : public AChipset {
    public:
        Component4094(std::string name);
        ~Component4094();

        nts::Tristate compute(std::size_t pin);

    public:
        bool checkOutputEnable();
        bool checkClock();
        bool checkStrobe();
        std::vector<nts::Tristate> _computeOnce(nts::Tristate);

    private:
        std::vector<nts::Tristate> internalStates;
};

#endif
