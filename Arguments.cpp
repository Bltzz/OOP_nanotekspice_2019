/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Arguments.cpp
*/

#include "Arguments.hpp"
#include <algorithm>

Arguments::Arguments(int ac, char **av)
{
    std::string path(av[1]);

    _path = path;
    for (int i = 2; i < ac; i++) {
        std::string str(av[i]);
        if (std::count(str.begin(), str.end(), '=') != 1)
            throw InvalidArgumentException("The arguments given are wrong");
        std::string name = str.substr(0, str.find_first_of("="));
        std::string val = str.substr(str.find_first_of("=") + 1, std::string::npos);
        try {
            int res = std::stoi(val.c_str());
            if (val.size() != 1 || res < 0 || res > 1)
                throw InvalidArgumentException("A given value is wrong");

            std::pair<std::string, int> pair(name, res);
            _initializer.push_back(pair);
        } catch (const std::invalid_argument &e) {
            throw InvalidArgumentException("A given value is wrong");

        }
    }
}

// if (ac < 2)
//     throw std::exception();//("No circuit file\n");

// Arguments::~Arguments()
// {
// }

void Arguments::setPath(const std::string &path)
{
    _path = path;
}

const std::string &Arguments::getPath() const
{
    return _path;
}

std::pair<std::string, int> Arguments::operator[](size_t index)
{
    try {
        if (index >= _initializer.size())
            throw std::out_of_range("Bad operation on vector\n");
        return _initializer.at(index);
    } catch (std::out_of_range &e){
        throw InvalidArgumentException(e.what(), "Vector");
    }
}

bool Arguments::getValue(const std::string &name) const
{
    for (size_t i = _initializer.size(); i > 0 ; i--) {
        if (_initializer.at(i - 1).first == name)
            return _initializer.at(i - 1).second;
    }
    throw InvalidArgumentException("An input value was not provided on the command line", name);
}
