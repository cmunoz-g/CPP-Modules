/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/12 14:12:15 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &toCopy ) {
	*this = toCopy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
	this->data = other._data;
	return (*this);
}

/**/

void BitcoinExchange::loadData( void ) {

	str::string line;
	std::ifstream db("./files/data.csv");

	if (!db.is_open()) {
		std::cerr << "Error: file not found" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::getline(db, line);
	while (std::getline(db, line)) {
		
	}
	
	


	
}


class BitcoinExchange {
	
public:

	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &toCopy );
	~BitcoinExchange();

	BitcoinExchange &operator=( const BitcoinExchange &other);

	void loadData( void );											// Loads data from the .csv onto the map
	void processInputFile( std::string file );						// Opens file and checks for errors, calculates

private:

	std::map<std::string, float> _data;

}