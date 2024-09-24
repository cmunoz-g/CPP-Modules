/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/24 12:52:02 by camunozg         ###   ########.fr       */
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

	if (!db.is_open()) {
		std::cerr << "Error: file not found" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::getline(db, line);
	while (std::getline(db, line)) {
		size_t pos;
		pos = line.find(',');
		if (pos == std::string::npos) {
			std::cerr << "Error: database is incorrect" << std::endl;
			db.close();
			exit(EXIT_FAILURE);
		}
		std::string date;
		date = line.substr(0, pos);

		float value;
		std::stringstream ss(line.substr(pos + 1));
		if (!(ss >> value)) {
			std::cerr << "Error: Failed to parse value" << std::endl;
			db.close();
			exit(EXIT_FAILURE);
		}
		if (value < 0) {
			std::cerr << "Error: Negative number" << std::endl;
			db.close();
			exit(EXIT_FAILURE);
		}
		_data.insert(std::make_pair(date, value));
	}
	db.close();
}

void BitcoinExchange::printData( void ) {
	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

// class BitcoinExchange {
	
// public:

// 	BitcoinExchange();
// 	BitcoinExchange( const BitcoinExchange &toCopy );
// 	~BitcoinExchange();

// 	BitcoinExchange &operator=( const BitcoinExchange &other);

// 	void loadData( void );											// Loads data from the .csv onto the map
// 	void processInputFile( std::string file );						// Opens file and checks for errors, calculates

// private:

// 	std::map<std::string, float> _data;

// }