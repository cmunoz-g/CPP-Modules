/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:57:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 14:09:57 by camunozg         ###   ########.fr       */
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
	std::cout << YELLOW << _name << " was photocopied\n" << RESET;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm &other ) {
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << RED << "The robotomy request form \"" << _name << "\" got thrown in the shredding machine!\n" << RESET;
}

/**/

void RobotomyRequestForm::execute( const Bureaucrat &executor) {
	std::uniform_real_distribution<> dis(0.0, 1.0);
	double random_number = dis(gen);

	if (!_signed)
		throw(FormNotSignedException());
	else if (executor.getGrade() > _execGrade)
		throw(GradeTooLowException());
		
	std::cout << MAGENTA << "* DRILLING NOISES *\n";
	if (random_number < 0.5)
		std::cout << _target << " has been succesfully robotomized!\n" << RESET;
	else 
		std::cout << RED << "The robotomy failed!\n" << RESET;
}
