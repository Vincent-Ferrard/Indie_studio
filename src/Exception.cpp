/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Exception
*/

#include "Exception.hpp"

Exception::Exception() : _msg() {}

Exception::Exception(const char *msg) : _msg(msg) {}

Exception::Exception(std::string const &msg) : _msg(msg) {}

const char *Exception::what() const noexcept { return (_msg.c_str()); }