/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:41:36 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/18 12:59:41 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat random_bureaucrat;
	Bureaucrat bob("Bob", 140);
	Bureaucrat another_bob(bob);
	random_bureaucrat = bob;

	std::cout << std::endl;
	
	bob.decrementGrade(10);				// Decrementing to 150
	//bob.decrementGrade(1);				// Trying to decrement under 150
	bob.incrementGrade(149);			// Incrementing to 1
	//bob.incrementGrade(1);				// Trying to increment over 1

	std::cout << std::endl;

	//Bureaucrat mike("Mike", 160);		// Trying to instantiate with invalid grades
	//Bureaucrat tony("Mike", -1);		// Trying to instantiate with invalid grades

	//std::cout << std::endl;
	
	std::cout << bob << "\n";					// << overload

	std::cout << std::endl;
	
	return (0);
	
}