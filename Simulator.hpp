/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Simulator.hpp
*/

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <iostream>
#include "Arguments.hpp"
#include "Circuit.hpp"
#include "ComponentOutput.hpp"

class Simulator
{
    public:
        Simulator(int ac, char **av);
        ~Simulator() = default;

        void display();
        void simulate();
        void loop();
        void dump();

        void mainLoop();

    protected:
        Arguments _arguments;
        Circuit _circuit;
        std::vector<std::unique_ptr<nts::IComponent>> &_components;
        std::vector<ComponentOutput> _outputs;
};

typedef struct command {
    std::string name;
    void (Simulator::*function)();
}command_t;

static const int COMMAND_SIZE = 4;
static const int FOUND_COMMAND = 5;

static const command_t COMMANDS[] = {
    {"display", &Simulator::display},
    {"simulate", &Simulator::simulate},
    {"loop", &Simulator::loop},
    {"dump", &Simulator::dump}
};

#endif /* SIMULATOR_HPP */
