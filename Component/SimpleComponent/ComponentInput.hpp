/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** ComponentInput.hpp
*/

#ifndef COMPONENTINPUT_HPP
#define COMPONENTINPUT_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class ComponentInput : public AChipset
{
public:
    explicit ComponentInput(std::string const name);
    ~ComponentInput();

    nts::Tristate compute(std::size_t pin);
    void dump() const;

public:
    void setValue(bool b);
    bool getValue() const { return this->input_value; }
    bool isSet() const { return this->_is_set; }
    void initialize() { this->_is_set = true; }

protected:
    bool input_value;
    bool _is_set;
};

#endif
