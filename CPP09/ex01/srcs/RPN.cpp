/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/26 12:58:08 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// while parsing the string, if i find a number, push it into the stack
// if an operator is found, pop the two numbers and perform the operation, push it back to the stack
// if a character thats not digit or operand is found, output error
// how should we manage 4 4 + + + +

RPN::RPN() {}

RPN::RPN( const RPN &toCopy ) {
	*this = toCopy;
}

RPN::~RPN() {}

RPN &RPN::operator=( const RPN &other ) {
	_numbers = other._numbers;
	return (*this);
}

/**/

void RPN::calculate( const std::string line ) {
	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == ' ')
			continue;
		else if (std::isdigit(line[i]))
			_numbers.push(line[i] - '0');
		else if (isOp(line[i]) && _numbers.size() > 1) {
			double a = _numbers.top();
			_numbers.pop();
			double b = _numbers.top();
			_numbers.pop();
			_numbers.push(performOp(a, b, line[i]));
		}
		else {
			std::cerr << "Error: invalid input" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if (_numbers.size() == 1)
		std::cout << "Result: " << _numbers.top() << std::endl;
	else
		std::cout << "Error: invalid input" << std::endl;
}

bool RPN::isOp( char c ) {
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

double RPN::performOp( double a, double b, char operand ) {
	if (operand == '+')
		return (b + a);
	else if (operand == '-')
		return (b - a);
	else if (operand == '/')
		return (b / a);
	else 
		return (b * a);
}
