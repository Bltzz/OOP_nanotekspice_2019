/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4008.hpp
*/

#ifndef COMPONENT4008_HPP
    #define COMPONENT4008_HPP

#include "AChipset.hpp"
#include <map>
#include <string>
#include <tuple>

class Component4008 : public AChipset {
    public:
        explicit Component4008(std::string name);
        ~Component4008();

        nts::Tristate compute(std::size_t pin);

    public:
        std::tuple<nts::Tristate, nts::Tristate> gate(bool, bool, bool);
        bool stateToBool(nts::Tristate);
        bool isUndefined(const nts::Tristate, const nts::Tristate);
};

#endif
