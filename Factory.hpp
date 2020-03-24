/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <memory>
#include "IComponent.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentClock.hpp"
#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "Component2716.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4017.hpp"
#include "Component4030.hpp"
#include "Component4040.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4094.hpp"
#include "Component4514.hpp"
#include "Component4801.hpp"

#include "DoesNotExistException.hpp"

class Factory
{
    public:
        Factory();
        ~Factory() = default;

        static std::unique_ptr<nts::IComponent> createComponent(const std::string type, const std::string &value);

    protected:
};

template<class T>
class Wrapper
{
    public:
        Wrapper();
        ~Wrapper() = default;

        static std::unique_ptr<nts::IComponent> construct(const std::string &value) {
            return std::unique_ptr<nts::IComponent>(new T(value));
        }

    protected:
};

#endif /* FACTORY_HPP */
