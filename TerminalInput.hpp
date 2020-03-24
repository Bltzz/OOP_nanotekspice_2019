/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** TerminalInput.hpp
*/

#ifndef TERMINALINPUT_HPP
#define TERMINALINPUT_HPP

#include <iostream>

class TerminalInput
{
    public:
        TerminalInput();
        ~TerminalInput() = default;

        static std::string getInput();
    protected:
};

#endif /* TERMINALINPUT_HPP */
