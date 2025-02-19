/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:24 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 12:01:33 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void printFloat( float num ) {
	if (num == static_cast<int>(num))
		std::cout << static_cast<int>(num);
	else {
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(2) << num;
		std::string formatedNum = oss.str();

		formatedNum.erase(formatedNum.find_last_not_of('0') + 1, std::string::npos);
		std::cout << formatedNum;
	}
}

bool isLeapYear( int year ) {
	if (year % 4 == 0) {
		if (year % 100 == 0)
			return (year % 400 == 0);
		return (true);
	}
	return (false);
}

int	strToInt( std::string str) {
	int	num;
	std::stringstream ss(str);

	if (!(ss >> num))
		return (-1);
	return (num);
}

void error(std::string errorMsg) {
	std::cerr << "Error: " << errorMsg << std::endl;
	exit(EXIT_FAILURE); 
}

int	main(int argc, char *argv[]) {
	
	if (argc != 2) 
		error ("could not open file.");
	
	BitcoinExchange btc;
	btc.loadData();
	btc.processInputFile(argv[1]);

	return (0);
}