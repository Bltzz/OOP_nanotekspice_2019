/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Parser.cpp
*/

#include "Parser.hpp"
#include <fstream>
#include <algorithm>
#include <exception>

Parser::Parser(const std::string &path)
    : _path(path)
{
}

const std::string &Parser::getPath() const
{
    return _path;
}

// Parser::~Parser()
// {
// }

std::string Parser::cleanStr(std::string str) const
{
    std::string res = "";
    if (str == "" || str.find_first_not_of(" \n\t\r") == std::string::npos)
        return res;
    std::string rest = str.substr(str.find_first_not_of(" \n\t\r"), std::string::npos);

    res = rest.substr(0, rest.find_first_of(" \n\t\r"));
    if (rest.find_first_of(" \n\t\r") == std::string::npos)
        return res;
    return res + ' ' + cleanStr(rest.substr(rest.find_first_of(" \n\t\r"), std::string::npos));
}

size_t Parser::getLength(std::string str) const
{
    if (str.size() == 0)
        return 0;
    return std::count(str.begin(), str.end(), ' ') + 1;
}

bool compareComponent(const std::string &str)
{
    if (str.compare(0, 4, "4001") == 0 || str.compare(0, 4, "4008") == 0 || str.compare(0, 4, "4011") == 0 || str.compare(0, 4, "4013") == 0)
        return true;
    if (str.compare(0, 4, "4017") == 0 || str.compare(0, 4, "4030") == 0 || str.compare(0, 4, "4040") == 0 || str.compare(0, 4, "4069") == 0)
        return true;
    if (str.compare(0, 4, "4071") == 0 || str.compare(0, 4, "4081") == 0 || str.compare(0, 4, "4094") == 0 || str.compare(0, 4, "4514") == 0)
        return true;
    if (str.compare(0, 4, "4801") == 0 || str.compare(0, 4, "2716") == 0 || str.compare(0, 6, "output") == 0)
        return true;
    if (str.compare(0, 5, "input") == 0 || str.compare(0, 5, "clock") == 0 || str.compare(0, 4, "true") == 0 || str.compare(0, 5, "false") == 0)
        return true;
    return false;
}

bool checkLinkSyntax(const std::string &str)
{
    std::string one = str.substr(0, str.find_first_of(" "));
    std::string two = str.substr(str.find_first_of(" ") + 1, std::string::npos);

    if (std::count(one.begin(), one.end(), ':') != 1)
        return false;
    if (std::count(two.begin(), two.end(), ':') != 1)
        return false;
    std::string pin = one.substr(one.find_first_of(":") + 1, std::string::npos);
    try {
        std::stoi(pin.c_str());
    } catch (const std::invalid_argument &error) {
        return false;
    }
    pin = two.substr(two.find_first_of(":") + 1, std::string::npos);
    try {
        std::stoi(pin.c_str());
    } catch (const std::invalid_argument &error) {
        return false;
    }
    return true;
}

std::vector<std::string> Parser::getFileContent() const
{
    std::ifstream file(_path);
    std::vector<std::string> content;
    bool chipset = false;
    bool links = false;
    size_t line = 1;

    if (file.fail()) // FileNotFoundException?
        return content;
    for (std::string str; std::getline(file, str); line++) {
        str = cleanStr(str);
        size_t length = getLength(str);
        if (length == 0 || str.at(0) == '#')
            continue;
        if (!chipset && !links && length != 1)
            throw DoesNotExistException("The syntax is invalid", _path);
        if (!chipset && !links && str != ".chipsets:")
            throw MissingChipsetError("The syntax is invalid", _path);
        else if (!chipset && !links) {
            chipset = true;
            content.push_back(str);
            continue;
        }
        if (chipset && !links && length > 2)
            throw DoesNotExistException("The syntax is invalid", _path);
        if (chipset && !links && length == 2 && !compareComponent(str))
            throw ComponentNameUnknownError("line " + std::to_string(line) + ": the component type is unknown", _path);
        if (chipset && !links && length == 1 && str != ".links:")
            throw MissingLinksError("The syntax is invalid", _path);
        else if (chipset && !links && length == 1) {
            chipset = false;
            links = true;
            content.push_back(str);
            continue;
        }
        if (!chipset && links && length != 2)
            throw MissingLinksError("The syntax is invalid", _path);
        if (!chipset && links && length == 2 && !checkLinkSyntax(str))
            throw MissingLinksError("The syntax is invalid", _path);
        content.push_back(str);
    }
    return content;
}