/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:06:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/20 14:05:22 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Random presidential pardon form", 25, 5, "Random target") {
	std::cout << CYAN << "A new presidential pardon form, with a random target, was dropped at the desk...\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Random presidential pardon form", 25, 5, target) {
	std::cout << CYAN << "A new presidential pardon form, with " << target << " as target, was dropped at the desk...\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &toCopy ) : AForm(toCopy) {
	*this = toCopy;
	std::cout << YELLOW << getName() << " was photocopied\n" << RESET;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << RED << "The presidential pardon form \"" << getName() << "\" got thrown in the shredding machine!\n" << RESET;
}

/**/

void PresidentialPardonForm::execute( const Bureaucrat &executor) const {
	execCheck(executor);	
	std::cout << MAGENTA << getTarget() << " has been pardoned by Zaphod Beeblebrox!\n" << RESET;
}