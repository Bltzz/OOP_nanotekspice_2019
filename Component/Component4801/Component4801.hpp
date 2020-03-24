/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** Component4801.hpp
*/

#ifndef COMPONENT4801_HPP
    #define COMPONENT4801_HPP

#include "AChipset.hpp"
#include <map>
#include <string>

class Component4801 : public AChipset {
    public:
        Component4801(std::string name);
        ~Component4801();

        nts::Tristate compute(std::size_t pin);

    public:
        bool checkMaster();
        bool checkOutputEnable();
        bool checkWriteEnable();
        nts::Tristate reverse(nts::Tristate);
        bool stateToBool(nts::Tristate);
        nts::Tristate boolToState(bool);
        unsigned int convertBinToDec(bool);

    private:
        bool matrix[8][128][8];
};

#endif
