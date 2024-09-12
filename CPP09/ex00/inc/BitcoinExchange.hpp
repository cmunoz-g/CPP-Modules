/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:20 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/12 14:01:21 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

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

#endif
