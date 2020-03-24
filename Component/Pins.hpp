/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Pins.hpp
*/

#ifndef PINS_HPP
    #define PINS_HPP

#include "Tristate.hpp"
#include "IComponent.hpp"
#include <stdio.h>

//forward declaration
namespace nts {
    class IComponent;
}

class Pins {
    public:
        enum Type{
            INPUT,
            OUTPUT,
            CLOCK
        };
        Pins(Type const t, int const pin, nts::Tristate const tri = nts::Tristate::UNDEFINED, nts::IComponent * const &c = nullptr);
        Pins(Pins const &p);
        ~Pins();
        Pins &operator=(Pins const &p);

        void setState(nts::Tristate const t) {this->state = t; }
        void setComponent(nts::IComponent &c) { this->comp = &c; }
        void setPin(int const pin) { this->pin = pin; }

        nts::IComponent *getComponent() const { return this->comp; }
        Type getType() const { return this->type; }
        nts::Tristate getState() const { return this->state; }
        int getPin() const { return this->pin; }

    private:
        nts::IComponent *comp;
        Type type;
        nts::Tristate state;
        int pin;
};

#endif

