/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Circuit.hpp
*/

#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "Parser.hpp"
#include "Arguments.hpp"

class Circuit
{
    public:
        Circuit(const std::string &path);
        const std::string &getPath() const;
        ~Circuit() = default;

        nts::IComponent &getComponent(const std::string &name) const;
        std::vector<std::unique_ptr<nts::IComponent>> &getComponents();
        void setAllLinks() const;
        std::string getUnlinked() const;
        void setValues(Arguments &arguments);

    protected:
        const std::string _path;
        Parser _parser;
        std::vector<std::unique_ptr<nts::IComponent>> _components;
};

#endif /* CIRCUIT_HPP */
