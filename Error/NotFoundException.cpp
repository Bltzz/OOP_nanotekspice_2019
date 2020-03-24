/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** NotFoundException.cpp
*/

#include "NotFoundException.hpp"

NotFoundException::NotFoundException(std::string const &message, std::string const &name){
    this->_message = message;
    this->_name = name;
}

std::string const &NotFoundException::getName() const{
    return this->_name;
}

FileNotFoundError::FileNotFoundError(std::string const &message, std::string const &name)
        : NotFoundException(message, name) {}

MissingChipsetError::MissingChipsetError(std::string const &message, std::string const &name)
        : NotFoundException(message, name) {}

MissingLinksError::MissingLinksError(std::string const &message, std::string const &name)
        : NotFoundException(message, name) {}


NotLinkedError::NotLinkedError(std::string const &message, std::string const &name)
        : NotFoundException(message, name) {}

InvalidArgumentException::InvalidArgumentException(std::string const &message, std::string const &name)
        : NotFoundException(message, name) {}
