/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"
#include "ComponentInput.hpp"
#include "Factory.hpp"
#include <exception>

Circuit::Circuit(const std::string &path)
    : _path(path), _parser(path)
{
}

const std::string &Circuit::getPath() const
{
    return _path;
}

// Circuit::~Circuit()
// {
// }

std::vector<std::unique_ptr<nts::IComponent>> &Circuit::getComponents()
{
    std::vector<std::string> content = _parser.getFileContent();
    std::vector<std::unique_ptr<nts::IComponent>> tmp;

    for (const auto &str : content)
    {
        if (str == ".chipsets:")
            continue;
        if (str == ".links:")
            break;
        std::string type = str.substr(0, str.find_first_of(" "));
        std::string name = str.substr(str.find_first_of(" ") + 1, std::string::npos);

        _components.push_back(std::move(Factory::createComponent(type, name)));
    }
    return _components;
}

nts::IComponent &Circuit::getComponent(const std::string &name) const
{
    for (size_t i = 0; i < _components.size(); i++)
    {
        nts::IComponent &component = *_components[i];
        if (component.getName() == name)
        {
            return component;
        }
    }
    throw ComponentNameUnknownError("Component name is unknown", "Name : " + name);
}

#include "Component4071.hpp"

void Circuit::setAllLinks() const
{
    std::vector<std::string> content = _parser.getFileContent();
    bool links = false;

    for (const auto &str : content)
    {
        if (str == ".links:")
        {
            links = true;
            continue;
        }
        if (links)
        {
            std::string one = str.substr(0, str.find_first_of(" "));
            std::string two = str.substr(str.find_first_of(" ") + 1, std::string::npos);
            std::string component_name_one = one.substr(0, one.find_first_of(":"));
            std::string component_name_two = two.substr(0, two.find_first_of(":"));
            int pin_one = std::stoi(one.substr(one.find_first_of(":") + 1, std::string::npos).c_str());
            int pin_two = std::stoi(two.substr(two.find_first_of(":") + 1, std::string::npos).c_str());
            nts::IComponent &component_one = getComponent(component_name_one);
            nts::IComponent &component_two = getComponent(component_name_two);
            component_one.setLink(pin_one, component_two, pin_two);
        }
    }
}

std::string Circuit::getUnlinked() const
{
    for (size_t i = 0; i < _components.size(); i++)
    {
        nts::IComponent &component = *_components[i];
        if (component.getType() == "output" && component.getMap().at(1)->getComponent() == nullptr)
            return component.getName();
    }
    return "";
}

void Circuit::setValues(Arguments &arguments)
{
    for (size_t i = 0; i < _components.size(); i++)
    {
        nts::IComponent &component = *_components[i];
        std::string type = component.getType();
        if (type == "input" || type == "clock")
        {
            auto input = dynamic_cast<ComponentInput &>(component);
            bool value = arguments.getValue(component.getName());
            input.setValue(value);
        }
    }
    for (size_t i = 0; i < arguments.size(); i++)
    {
        auto &component = this->getComponent(arguments[i].first);
        std::string type = component.getType();
        if (type != "input" && type != "clock")
            throw InputDoesNotExistError("A provided input is unknown", type);
    }
}
