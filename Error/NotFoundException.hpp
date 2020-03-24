/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** NotFoundException.hpp
*/

#ifndef NOTFOUNDEXCEPTION_HPP
    #define NOTFOUNDEXCEPTION_HPP

#include <string>
#include <exception>

class NotFoundException : public std::exception
{
    public:
        NotFoundException(std::string const &message,
                std::string const &component = "Unknown");

        std::string const &getName() const;
        const char *what() const throw() override { return _message.data(); }
    protected:
        std::string _message;
        std::string _name;
};

class FileNotFoundError : public NotFoundException {
    public:
        FileNotFoundError(std::string const &message = "File not found, please check the provided Path and syntax", std::string const &name = "Unknown");
};

class MissingChipsetError : public NotFoundException {
    public:
        MissingChipsetError(std::string const &message = "The given file does not contain a \".chipset\" specifier", std::string const &name = "Unknown");
};

class MissingLinksError : public NotFoundException {
    public:
        MissingLinksError(std::string const &message = "The given file does not contain a \".links\" specifier", std::string const &name = "Unknown");
};

class NotLinkedError : public NotFoundException {
    public:
        NotLinkedError(std::string const &message = "The given link is not possible or does not exist", std::string const &name = "Unknown");
};

class InvalidArgumentException : public NotFoundException{
    public:
        InvalidArgumentException(std::string const &message = "Type does not match Output Type.", std::string const &name = "Unknown");
};
#endif /* NOTFOUNDEXCEPTION_HPP */