/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:14:20 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 10:49:47 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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