/*
** EPITECH PROJECT, 2019
** cpp_pool_2019
** File description:
** Simulator.cpp
*/

#include "Simulator.hpp"
#include <memory>
#include <algorithm>
#include "ComponentInput.hpp"
#include "ComponentClock.hpp"
#include "TerminalInput.hpp"

Simulator::Simulator(int ac, char **av)
    : _arguments(ac, av), _circuit(_arguments.getPath()), _components(_circuit.getComponents())
{
    _circuit.setAllLinks();
    std::string unlinked = _circuit.getUnlinked();
    if (unlinked.size() != 0)
        throw InputDoesNotExistError("An output is not linked to anything", "name : " + unlinked);
    _circuit.setValues(_arguments);
    for (size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getType() == "output") {
            auto &an_output = dynamic_cast<ComponentOutput &>(*_components[i]);
            _outputs.push_back(an_output);
        }
    }
    std::sort(_outputs.begin(), _outputs.end());
}

// Simulator::~Simulator()
// {
// }

void Simulator::display()
{
    for (size_t i = 0; i < _outputs.size() && _outputs[i].getMap().at(1)->getComponent() != nullptr; i++) {
        //_outputs[i].dump();
        std::cout << _outputs[i].getName() << "=" << _outputs[i].getValue() << std::endl;
    }
}

void Simulator::simulate()
{
    for (size_t i = 0; i < _outputs.size(); i++) {
        _outputs[i].compute(1);
    }
    for (size_t i = 0; i < _components.size(); i++) {
        nts::IComponent &component = *_components[i];
        if (component.getType() == "clock") {
            auto &comp = dynamic_cast<ComponentClock &>(component);
            comp.setValue(!comp.getValue());
        }
    }

}

void Simulator::loop()
{
    while (42) {
        simulate();
    }
}

void Simulator::dump()
{
    for (size_t i = 0; i < _components.size() && _components[i] != nullptr; i++) {
        _components[i]->dump();
    }
}

void Simulator::mainLoop()
{
    simulate();
    display();
    std::string input = TerminalInput::getInput();

    while (input != "exit") {
        int i = 0;
        for (; i < COMMAND_SIZE; i++)
            if (input == COMMANDS[i].name) {
                (this->*(COMMANDS[i].function))();
                i = FOUND_COMMAND;
            }
        if (i == COMMAND_SIZE) {
            if (std::count(input.begin(), input.end(), '=') == 0)
                throw DoesNotExistException("Unknown command");
            std::string name = input.substr(0, input.find_first_of("="));
            std::string val = input.substr(input.find_first_of("=") + 1, std::string::npos);
            try {
                int res = std::stoi(val.c_str());
                if (val.size() != 1 || res < 0 || res > 1)
                    throw InputDoesNotExistError();
                auto &component = _circuit.getComponent(name);
                if (component.getType() != "input" && component.getType() != "clock")
                    throw ComponentNameUnknownError("The component is unknown");
                auto &comp = dynamic_cast<ComponentInput &>(component);
                comp.setValue(static_cast<bool>(res));
            } catch (const std::invalid_argument &e) {
                //std::cout << e.what();
                throw InvalidArgumentException("a given value is wrong");

            }
        }
        input = TerminalInput::getInput();
    }
}
