/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** main.cpp
*/

#include "Simulator.hpp"
#include "NotFoundException.hpp"
#include "DoesNotExistException.hpp"


int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Not enough Arguments. " << std::endl << "Type ./nanotekspice -h for help." << std::endl;
        return 84;
    }
    try {
        Simulator simulation(ac, av);
        simulation.mainLoop();
    } catch ( NotFoundException &e ){
        std::cout << e.what() << std::endl;
        std::cout << "Error at Component: " << e.getName() << std::endl;
        return 84;
    } catch ( DoesNotExistException &e ){
        std::cout << e.what() << std::endl;
        std::cout << e.getName() << std::endl;
        return 84;
    } catch (std::exception &e){
        std::cout << e.what();
        return 84;
    }
    return 0;
}