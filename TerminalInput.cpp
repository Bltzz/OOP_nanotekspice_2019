/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** TerminalInput.cpp
*/

#include "TerminalInput.hpp"

TerminalInput::TerminalInput()
{
}

// TerminalInput::~TerminalInput()
// {
// }

std::string TerminalInput::getInput()
{
    std::string input;

    std::cout << "> ";
    std::cin >> input;
    if (std::cin.eof())
        return "exit";
    return input;
}
