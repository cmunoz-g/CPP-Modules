/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:26:02 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 10:58:01 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	Array<int> intArray(5);	
	Array<char> charArray(3);

	for (std::size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
    }

	charArray[0] = 'A';
	charArray[1] = 'B';
	charArray[2] = 'C';

	for (int i = 0; i < 3; i++)
		std::cout << charArray[i];

	std::cout << std::endl;
	
	for (int i = 0; i < 5; i++) 
		std::cout << intArray[i];
	
	std::cout << std::endl;

	try {
		intArray[100];
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}