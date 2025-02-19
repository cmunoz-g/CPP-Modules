/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:23 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 11:59:40 by cmunoz-g         ###   ########.fr       */
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
	std::ifstream file(fileName.c_str());

	if (!file.is_open())
		error("could not open file");
		
	std::getline(file, line); 
	// while line, read line
	while (std::getline(file, line)) {
		if (!isValidLine(line))
		{
			std::cerr << "Error: bad input => " << line << std::endl; 
			continue;
		}
		
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
	}
}

bool BitcoinExchange::isValidLine( std::string line ) {
	if (line.empty() || line.length() < 14)
		return (false);
	// find pipe
	// if there inst, wrong line input
	size_t pos;
	pos = line.find('|');
	if (pos == std::string::npos) {
		return (false);
	}
	if (pos > 0 && pos < line.size() - 1)
		return (line[pos - 1] == ' ' && line[pos + 1] == ' ');
	return (true);
}

bool BitcoinExchange::checkDate( std::string date ) {
	
	// if positions not 4 or 7 are not numbers
	// if positions 4 and 7 are not '-'

	for (size_t i = 0; i < date.size(); i++) {
		if ((i == 4 || i == 7) && date[i] != '-')
			return (false);
		else if ((i != 4 && i != 7) && !std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int year = strToInt(date.substr(0, 4));
	int month = strToInt(date.substr(5, 2));
	int day = strToInt(date.substr(8, 2));

	if (year < 2009 || month < 0 || day < 0)
		return (false);

	// if month is out of bounds
	if (month < 1 || month > 12)
		return (false);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(month))
		daysInMonth[1] = 29;

	// if day exceeds month limit
	if (day > daysInMonth[month - 1])
		return (false);

	// if date is lower than 2009-01-02 
	if (year == 2009 && month == 1 && day == 1)
		return (false);
	
	return (true);
}

void BitcoinExchange::calculate( std::string date, float value) {
	// iterator that starts at date
	std::map<std::string, float>::iterator it = _data.find(date);

	// if data.end() meaning update it to _data.lower_bound(date), print
	if (it == _data.end())
		it = _data.lower_bound(date);
	std::cout << date << " => ";
	printFloat(value);
	std::cout << " = ";
	printFloat(value * it->second); 
	std::cout << std::endl;
}
	