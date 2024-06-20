/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:14:20 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/20 14:07:10 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Decidir en CPP05 si quiero que al copiar con =, se copie el estado de firmado o no.

int main() {
	PresidentialPardonForm pres_form("Mike");
	RobotomyRequestForm robo_form("Mike");
	ShrubberyCreationForm sh_form("42");

	Bureaucrat mike("Mike", 100);
	std::cout << std::endl;
	mike.signForm(sh_form);
	mike.executeForm(sh_form);

	std::cout << std::endl;

	Bureaucrat john("John", 72);
	john.signForm(robo_form);
	try {
		john.executeForm(robo_form);					// Trying to execute with too low of a grade
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	john.incrementGrade(71);
	john.executeForm(robo_form);

	try {
		john.executeForm(pres_form);					// Trying to execute without signing
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	john.signForm(pres_form);							
	pres_form.execute(john);							// Executing the form directly

	std::cout << std::endl;
	
	return (0);
}