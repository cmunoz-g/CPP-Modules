/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:30:02 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/27 10:56:02 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(std::string literal) {
	if (literal.size() == 1 && ((literal[0] >= 0 && literal[0] <= 127) && !std::isdigit(literal[0])))
			return  (true);
	return (false);
}

bool isInt(std::string literal) {
	std::string::size_type i = 0;
	
	if (literal[i] == '-')
		i++;
	while (i < literal.size()) {
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isFloat(std::string literal) {
	bool foundPoint = false;
	std::string::size_type i = 0;
	std::string::size_type size = literal.size();

	if (literal[i] == '-')
		i++;
	while (i < size - 1) {
		if (!std::isdigit(literal[i])) {
			if (literal[i] == '.' && !foundPoint)
				foundPoint = true;
			else 
				return (false);
		}
		i++;
	}
	if (literal[size - 1] == 'f' && foundPoint) 
		return (true);
	return (false);
}

bool isDouble(std::string literal) {
	bool foundPoint = false;
	std::string::size_type i = 0;

	if (literal[i] == '-')
		i++;
	while (i < literal.size()) {
		if (!std::isdigit(literal[i])) {
			if (literal[i] == '.' && !foundPoint)
				foundPoint = true;
			else 
				return (false);
		}
		i++;
	}
	if (foundPoint)
		return (true);
	return (false);
}

bool stringToLongLong( std::string literal, DataTypes &data) {
	std::stringstream ss(literal);
	ss >> data.l;

	if (ss.fail() || !ss.eof()) {
		return (false);
	}
	
	return (true);
}

bool isOutOfRange( std::string literal, DataTypes &data) {
	if (!stringToLongLong(literal, data)) {
		std::cerr << "Error while converting to long long\n";
 		exit(EXIT_FAILURE);
	}
	if (data.l >= std::numeric_limits<int>::min() && data.l <= std::numeric_limits<int>::max()) {
		return (false);
	}
	else {
		data.out_of_range_int = true;
		return (true);
	}
}

bool isDecimalPartZero( double value ) {
	double intPart;
	double fracPart = std::modf(value, &intPart);
	return (fracPart == 0.0);
}