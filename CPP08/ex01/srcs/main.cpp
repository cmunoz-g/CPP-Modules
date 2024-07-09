/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:26:09 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 13:52:24 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span span(5);

	for (int i = 0; i < 5; i++) {
		span.addNumber(i * 2);
		std::cout << span.getNbrs()[i] << " ";
	}

	std::cout << std::endl << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl << std::endl;

	Span secondSpan(100000);
	std::vector<int> randomNumbers;
	
	randomNumbers.reserve(50000);
	std::srand(std::time(0));
	for (int i = 0; i < 50000; i++) {
 		int randomNumber = 0 + (std::rand() % (100000 - 0 + 1));
		randomNumbers.push_back(randomNumber);
	}
	
	try {
		secondSpan.longestSpan();
	} catch( std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	secondSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

	std::cout << std::endl;
	std::cout << "Longest span: " << secondSpan.longestSpan() << std::endl;
	std::cout << "Shortest span: " << secondSpan.shortestSpan() << std::endl;
		 
	return (0);
}