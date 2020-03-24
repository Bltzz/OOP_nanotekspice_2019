/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "IComponent.hpp"

class Parser
{
    public:
        Parser(const std::string &filepath);
        const std::string &getPath() const;
        ~Parser() = default;

        std::string cleanStr(std::string str) const;
        size_t getLength(std::string str) const;
        std::vector<std::string> getFileContent() const;

    protected:
        const std::string _path;
};

#endif /* PARSER_HPP */
