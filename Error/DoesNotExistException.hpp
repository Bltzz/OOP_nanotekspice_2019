/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** DoesNotExistException.hpp
*/


#ifndef DOESNOTEXISTEXCEPTION_HPP
    #define DOESNOTEXISTEXCEPTION_HPP

#include <string>
#include <exception>

class DoesNotExistException : public std::exception
{
    public:
        DoesNotExistException(std::string const &message,
                std::string const &component = "Unknown");

        std::string const &getName() const;
        const char *what() const throw() override {return _message.data();}
    protected:
        std::string _message;
        std::string _name;
};

class ComponentTypeUnknownError : public DoesNotExistException{
    public:
        ComponentTypeUnknownError(std::string const &message = "Type not found", std::string const &name = "Unknown");
};

class ComponentNameUnknownError : public DoesNotExistException {
    public:
        ComponentNameUnknownError(std::string const &message = "Name not found", std::string const &name = "Unknown");
};

class PinDoesNotExistError : public DoesNotExistException {
    public:
        PinDoesNotExistError(std::string const &message = "Pin does not exist", std::string const &name = "Unknown");
};

class ForbiddenNameError : public DoesNotExistException {
    public:
        ForbiddenNameError(std::string const &message = "Name already exists or is forbidden!", std::string const &name = "Unknown");
};

class InputDoesNotExistError : public DoesNotExistException {
    public:
        InputDoesNotExistError(std::string const &message = "No input value provided", std::string const &name = "Unknown");

};


#endif /* DOESNOTEXISTEXCEPTION_HPP */
