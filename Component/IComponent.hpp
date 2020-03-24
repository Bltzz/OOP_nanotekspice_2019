/*
** EPITECH PROJECT, 2019
** bootstrap_NanoTekSpice
** File description:
** IComponent.hpp
*/
//#pragma once
#ifndef ICOMPONENT_HPP
    #define ICOMPONENT_HPP

#include "Pins.hpp"
#include "Tristate.hpp"
#include "DoesNotExistException.hpp"
#include "NotFoundException.hpp"
#include <map>

// forward declaration
class Pins;

namespace nts {
    class IComponent{
        public:
            virtual ~IComponent() = default;
        public:
            virtual nts::Tristate compute(std::size_t  pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
        public:
            virtual void setName(std::string name) = 0;

            virtual std::map<int, Pins *> getMap() const = 0;
            virtual std::string getName() const = 0;
            virtual std::string getType() const = 0;



    };
}

#endif