/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** AChipset.hpp
*/

#ifndef ACHIPSET_HPP
    #define ACHIPSET_HPP

#include "IComponent.hpp"
#include <map>
#include <string>

class AChipset : public nts::IComponent{
    public:

        virtual nts::Tristate compute(std::size_t  pin = 1) = 0;
        virtual void dump() const;

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void setName(std::string name) { this->name = name; }

        std::string getName() const { return this->name; }
        std::map<int, Pins *> getMap() const { return this->pins; }
        std::string getType() const { return this->type; }

    protected:
        std::map<int, Pins *> pins;
        std::string name;
        std::string type;
        int numPins;
};

#endif