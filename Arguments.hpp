/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Arguments.hpp
*/

#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include "DoesNotExistException.hpp"
#include "NotFoundException.hpp"
#include <iostream>
#include <vector>

class Arguments
{
    public:
        Arguments(int ac, char **av);
        ~Arguments() = default;

        void setPath(const std::string &path);
        const std::string &getPath() const;

        std::pair<std::string, int> operator[](size_t index);
        size_t size() {return _initializer.size();}
        bool getValue(const std::string &name) const;

    protected:
        std::string _path;
        std::vector<std::pair<std::string, int>> _initializer;
};

#endif /* ARGUMENTS_HPP */
