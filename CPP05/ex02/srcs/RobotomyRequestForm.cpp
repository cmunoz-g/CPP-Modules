/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:57:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/20 14:05:42 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Random robotomy form", 72, 45, "Random target") {
	std::cout << CYAN << "A new robotomy form, with a random target, was dropped at the desk...\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Random robotomy form", 72, 45, target) {
	std::cout << CYAN << "A new robotomy form, with " << target << " as target, was dropped at the desk...\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &toCopy ) : AForm(toCopy) {
	*this = toCopy;
	std::cout << YELLOW << getName() << " was photocopied\n" << RESET;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << RED << "The robotomy request form \"" << getName() << "\" got thrown in the shredding machine!\n" << RESET;
}

/**/

void RobotomyRequestForm::execute( const Bureaucrat &executor) const {
	srand(static_cast<unsigned int>(time(0))); 						// Seeds the random number generator (initializes it with a starting value)
	int random_number = rand() % 2;									// Generates a random number either 0 or 1 (any number divided by 2 has either 0 or 1 as remainders)

	execCheck(executor);
		
	std::cout << MAGENTA << "* DRILLING NOISES *\n";
	if (random_number == 0)
		std::cout << getTarget() << " has been succesfully robotomized!\n" << RESET;
	else 
		std::cout << RED << "The robotomy failed!\n" << RESET;
}
