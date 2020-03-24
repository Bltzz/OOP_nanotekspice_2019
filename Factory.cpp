/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Factory.cpp
** Creates differnt Components while using Template Class
*/

#include "Factory.hpp"

Factory::Factory()
{
}

// Factory::~Factory()
// {
// }

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string type, const std::string &value)
{
    if (type == "input")
        return Wrapper<ComponentInput>::construct(value);
    else if (type == "output")
        return Wrapper<ComponentOutput>::construct(value);
    else if (type == "true")
        return Wrapper<ComponentTrue>::construct(value);
    else if (type == "false")
        return Wrapper<ComponentFalse>::construct(value);
    else if (type == "clock")
        return Wrapper<ComponentClock>::construct(value);
    else if (type == "2716")
        return Wrapper<Component2716>::construct(value);
    else if (type == "4001")
        return Wrapper<Component4001>::construct(value);
    else if (type == "4008")
        return Wrapper<Component4008>::construct(value);
    else if (type == "4011")
        return Wrapper<Component4011>::construct(value);
    else if (type == "4013")
        return Wrapper<Component4013>::construct(value);
    else if (type == "4017")
        return Wrapper<Component4017>::construct(value);
    else if (type == "4030")
        return Wrapper<Component4030>::construct(value);
    else if (type == "4040")
        return Wrapper<Component4040>::construct(value);
    else if (type == "4069")
        return Wrapper<Component4069>::construct(value);
    else if (type == "4071")
        return Wrapper<Component4071>::construct(value);
    else if (type == "4081")
        return Wrapper<Component4081>::construct(value);
    else if (type == "4094")
        return Wrapper<Component4094>::construct(value);
    else if (type == "4514")
        return Wrapper<Component4514>::construct(value);
    else if (type == "4801")
        return Wrapper<Component4801>::construct(value);
    throw ComponentTypeUnknownError("Component Type " + type + " unknown.");
}