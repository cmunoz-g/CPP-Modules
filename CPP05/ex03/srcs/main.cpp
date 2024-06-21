/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:14:20 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/21 10:04:46 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Decidir en CPP05 si quiero que al copiar con =, se copie el estado de firmado o no.

int main() {
	Bureaucrat mike("Mike", 1);
	Intern intern;
	AForm *form = NULL;

	std::cout << std::endl;
	
	form = intern.makeForm("Random form", "Random target");		// Intern creates a non existent form 
	form = intern.makeForm("PresidentialPardonForm", "John");

	std::cout << std::endl << (*form) << std::endl;

	mike.signForm(*form);
	mike.executeForm(*form);
	
	delete (form);
	
	return (0);
}