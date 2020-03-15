/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <cstring>
#include <exception>
#include <string>

class Exception : public std::exception {
      private:
	std::string _msg;

      public:
	Exception();
	Exception(const char *msg);
	Exception(std::string const &msg);
	const char *what() const noexcept override;
};

#endif /* !EXCEPTION_HPP_ */