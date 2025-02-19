/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:20 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 12:01:19 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

bool	isLeapYear( int year );
int		strToInt( std::string str);
void	error(std::string errorMsg);
void 	printFloat( float num );

class BitcoinExchange {
	
public:

	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &toCopy );
	~BitcoinExchange();

	BitcoinExchange &operator=( const BitcoinExchange &other);

	void loadData( void );											// Loads data from the .csv onto the map
	void processInputFile( std::string fileName );					// Opens file and checks for errors, calculates
	void calculate(std::string date, float value);
	static bool checkDate( std::string date );
	static bool isValidLine(std::string line);


private:

	std::map<std::string, float> _data;
	
};

#endif
