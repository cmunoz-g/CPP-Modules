/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/24 14:02:14 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &toCopy ) {
	*this = toCopy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
	this->_data = other._data;
	return (*this);
}

/**/

void BitcoinExchange::loadData( void ) {

	std::string line;
	std::ifstream db("./files/data.csv");

	if (!db.is_open())
		error("database file not found");
		
	std::getline(db, line);
	while (std::getline(db, line)) {
		size_t pos;
		pos = line.find(',');
		if (pos == std::string::npos) {
			db.close();
			error("database is incorrect");
		}
		std::string date;
		date = line.substr(0, pos);

		float value;
		std::stringstream ss(line.substr(pos + 1));
		if (!(ss >> value)) {
			db.close();
			error("failed to parse number");
		}
		if (value < 0) {
			db.close();
			error("negative number");
		}
		_data.insert(std::make_pair(date, value));
	}
	db.close();
}

void BitcoinExchange::processInputFile( std::string fileName ) {
	// open the file
	std::string line;
	std::ifstream file(fileName);

	if (!file.is_open())
		error("could not open file");
		
	std::getline(file, line); 
	// while line, read line
	while (std::getline(file, line)) {
		if (!isValidLine(line))
			std::cerr << "Error: wrong line input." << std::endl;

		std::string date = line.substr(0, 10);
		
		float value;
		std::stringstream ss(line.substr(13));
		if (!(ss >> value)) {
			std::cerr << "Error: value is not a number." << std::endl;
		}
		// check correct date, value
		// if error at any point, print && continue;

		else if (!checkDate(date))
			std::cerr << "Error: bad input => " << date << std::endl;
		else if (value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cerr << "Error: too large a number." << std::endl;
		// print
		else
			calculate(date, value); // check if date exists, if not go for closest (lower_bound)
			// lower bound is a method of std::map, check what happens if i remove 2009-01-02 condition from checkDate
	}
}

bool BitcoinExchange::isValidLine( std::string line ) {
	if (!line || line == "" || line.length() < 14)
		return (0);
	// find pipe
	// if there inst, wrong line input
	// if there is only whitespaces before or after, wrong line input
}

bool BitcoinExchange::checkDate( std::string date ) {
	// if positions not 4 or 6 are not numbers
	// if positions 4 and 6 are not '-'
	// if month exceeds 12
	// if day exceeds month limit
	// if date is lower than 2009-01-02
}

void BitcoinExchange::calculate( std::string date, float value) {
	// iterator that starts at date
	// if its not data.end() meaning date exists, print
	// else update it to _data.lower_bound(date), print
}
	