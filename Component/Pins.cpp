/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Pins.cpp
*/

#include "Pins.hpp"

Pins::Pins(Type const t, int const pin, nts::Tristate const tri, nts::IComponent * const &c){
    this->comp = c;
    this->type = t;
    this->state = tri;
    this->pin = pin;
}

Pins::Pins(Pins const &p){
    this->comp = p.comp;
    this->type = p.type;
    this->state = p.state;
    this->pin = p.pin;
}

Pins &Pins::operator=(Pins const &p){
    this->comp = p.comp;
    this->type = p.type;
    this->state = p.state;
    this->pin = p.pin;

    return *this;
}

Pins::~Pins(){}