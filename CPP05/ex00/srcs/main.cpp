/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:41:36 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 11:47:40 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() { 

	Bureaucrat random_bureaucrat;
	Bureaucrat bob("Bob", 140);
	Bureaucrat another_bob(bob);
	random_bureaucrat = bob;

	std::cout << std::endl;
	
	bob.decrementGrade(10);						// Decrementing to 150
	
	try {
		bob.decrementGrade(1);					// Trying to decrement under 150	
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;		// We handle the caught exception by calling what(), which was overloaded.
	}
	
	bob.incrementGrade(149);					// Incrementing to 1
	
	try {
		bob.incrementGrade(1);					// Trying to increment over 1
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat mike("Mike", 160);			// Trying to instantiate with invalid grades
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat tony("Mike", -1);			// Trying to instantiate with invalid grades
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << bob << std::endl;				// << overload

	std::cout << std::endl;
	
	return (0);
	
}