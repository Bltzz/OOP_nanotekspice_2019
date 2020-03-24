/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** DoesNotExistException.cpp
*/

#include "DoesNotExistException.hpp"

DoesNotExistException::DoesNotExistException(std::string const &message, std::string const &name){
    this->_message = message;
    this->_name = name;
}

std::string const &DoesNotExistException::getName() const{
    return this->_name;
}

ComponentTypeUnknownError::ComponentTypeUnknownError(std::string const &message, std::string const &name)
        : DoesNotExistException(message, name){}

ComponentNameUnknownError::ComponentNameUnknownError(std::string const &message, std::string const &name)
        : DoesNotExistException(message, name){}

PinDoesNotExistError::PinDoesNotExistError(std::string const &message, std::string const &name)
        : DoesNotExistException(message, name){}

ForbiddenNameError::ForbiddenNameError(std::string const &message, std::string const &name)
        : DoesNotExistException(message, name){}

InputDoesNotExistError::InputDoesNotExistError(std::string const &message, std::string const &name)
        : DoesNotExistException(message, name){}