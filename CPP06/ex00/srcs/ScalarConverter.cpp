/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:27:36 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/25 10:22:38 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( ScalarConverter &toCopy ) {
	*this = toCopy;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter &other ) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {}

/**/

void ScalarConverter::convert( std::string literal ) {
	DataTypes data;
	data.out_of_range_int = false;
	data.impossible_int = false;
	data.impossible_char = false;
	data.non_displayable_char = false;

	char type = getType(literal);
	
	if (type == 'e') {
		std::cerr << "Wrong format\n";
		exit(EXIT_FAILURE);
	}
	else if (type == 'c') {
		data.c = literal[0];
		data.i = static_cast<int>(data.c);
		data.f = static_cast<float>(data.c);
		data.d = static_cast<double>(data.c);
	}
	else if (type == 'i') {
		if (isOutOfRange( literal, data )) {
			data.f = static_cast<float>(data.l);
			data.d = static_cast<double>(data.l);
			data.impossible_char = true;
		}
		else {
			data.i = atoi(literal.c_str());
			if (data.i <= 127 && data.i >= 0)
				data.c = static_cast<char>(data.i);
			else
				data.impossible_char = true;
			data.f = static_cast<float>(data.i);
			data.d = static_cast<double>(data.i);
		}
	}
	else if (type == 'f') {
		std::string temp = literal.erase(literal.size() - 1);
		std::stringstream ss(temp);
		ss >> data.f;
		data.i = static_cast<int>(data.f);
		data.d = static_cast<double>(data.f);
		if (data.i <= 127 && data.i >= 0)
			data.c = static_cast<char>(data.i);
		else
			data.impossible_char = true;
	}
	else if (type == 'd') {
		std::stringstream ss(literal);
		ss >> data.d;
		data.i = static_cast<int>(data.d);
		data.f = static_cast<float>(data.d);
		if (data.i <= 127 && data.i >= 0)
			data.c = static_cast<char>(data.i);
		else
			data.impossible_char = true;
	}	
	printValues(data);
}

/**/
 
char getType( std::string literal ) {
	if (literal.empty())
		return('e');
	else if (isChar(literal))
		return ('c');
	else if (isInt(literal))
		return ('i');
	else if (isFloat(literal))
		return ('f');
	else if (isDouble(literal)) 
		return ('d');
	return ('e');
}

bool isDecimalPartZero( double value ) {
	double intPart;
	double fracPart = std::modf(value, &intPart);
	return (fracPart == 0.0);
}

void printValues( DataTypes data ) {
	std::cout << "char: ";
	if (data.impossible_char)
		std::cout << "impossible";
	else if ((data.c >= 0 && data.c < 32) || data.c == 127)
		std::cout << "Non displayable";
	else
		std::cout << data.c;
	
	std::cout << "\nint: ";
	if (data.out_of_range_int)
		std::cout << "out of range int";
	else if (data.impossible_int)
		std::cout << "impossible";
	else
		std::cout << data.i;
	
	std::cout << "\nfloat: ";
	std::cout << data.f;
	if (isDecimalPartZero(data.f))
		std::cout << ".0";
	std::cout << "f";

	std::cout << "\ndouble: ";
	std::cout << data.d;
	if (isDecimalPartZero(data.d))
		std::cout << ".0";
	std::cout << std::endl;
}