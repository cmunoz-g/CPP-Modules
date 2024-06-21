/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:20:34 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/21 09:17:38 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << CYAN << "A new intern was hired!\n" << RESET;
}

Intern::Intern( Intern &toCopy ) {
	std::cout << YELLOW << "An intern was cloned!\n" << RESET;
	*this = toCopy;
}

Intern &Intern::operator=( Intern &other ) {
	(void)other;
	return (*this);
}

Intern::~Intern() {
	std::cout << RED << "An intern was fired!\n" << RESET;
}

/**/

AForm *Intern::makeForm( std::string formName , std::string formTarget ) const {
	AForm *(*ft_ptrs[])(const std::string target) = {makePresident, makeRobotomy, makeShrubbery};
	std::string str_ptrs[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++) {
		if (formName == str_ptrs[i]) {
			std::cout << MAGENTA << "Intern creates " << formName << RESET << std::endl;
			return (ft_ptrs[i](formTarget));
		}
	}
	std::cerr << RED << "There is no type of form named " << formName << "!\n" << RESET;
	return (NULL); 
}

AForm *Intern::makePresident( std::string target ) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy( std::string target ) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery( std::string target ) {
	return (new ShrubberyCreationForm(target));
}
