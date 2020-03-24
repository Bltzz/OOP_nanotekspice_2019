/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Tristate.hpp
** enum is needed in Pins and IComponent
*/

#ifndef TRISTATE_HPP
    #define TRISTATE_HPP

namespace nts{
    enum Tristate{
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    // static std::map<nts::Tristate, std::string> states = { // for Dump method
    //     { nts::Tristate::UNDEFINED, "undefined" },
    //     { nts::Tristate::FALSE, "false" },
    //     { nts::Tristate::TRUE, "true" }
    // };
};

#endif