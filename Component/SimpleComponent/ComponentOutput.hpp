/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentOutput.hpp
*/

#ifndef COMPONENTOUTPUT_HPP
    #define COMPONENTOUTPUT_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class ComponentOutput : public AChipset {
    public:
        explicit ComponentOutput(std::string name);
        ~ComponentOutput();

        nts::Tristate compute(std::size_t pin);
        bool operator<(const ComponentOutput &other) const;
        ComponentOutput &operator=(const ComponentOutput &other);
        void dump();

    public:
        void setValue(nts::Tristate value);
        nts::Tristate getValue() const { return this->output_value; }


    protected:
        nts::Tristate output_value;
};

#endif
