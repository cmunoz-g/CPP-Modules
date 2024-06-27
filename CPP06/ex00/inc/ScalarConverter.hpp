/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:21:03 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/27 11:10:18 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <limits>

struct DataTypes {
	char c;	
	int i;
	float f;
	double d;

	bool out_of_range_int;
	bool impossible_char;
	bool impossible_int;
	bool non_displayable_char;
	long long l;
};

class ScalarConverter {

public:
	/* Member functions */
	static void convert( std::string literal );

private:
	/* Constructors, Destructor, Operators */
	ScalarConverter( void );
	ScalarConverter( ScalarConverter &toCopy );
	ScalarConverter &operator=( ScalarConverter &other );
	virtual ~ScalarConverter( void );


};

char getType( std::string literal );
void printValues( DataTypes data );
bool checkIfPseudo( std::string literal, DataTypes &data);
bool isChar( std::string literal );
bool isInt( std::string literal );
bool isFloat( std::string literal );
bool isDouble( std::string literal );
bool isOutOfRange( std::string literal, DataTypes &data);
bool isDecimalPartZero( double value );

#endif