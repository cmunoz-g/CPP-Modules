/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:24 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/24 13:06:34 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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