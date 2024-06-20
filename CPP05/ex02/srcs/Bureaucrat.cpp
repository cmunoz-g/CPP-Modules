/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:09:22 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/20 14:00:26 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Unnamed Bureaucrat"), _grade(150) {
	std::cout << CYAN << _name << " with a grade of " << _grade << " was just hired!" << RESET << "\n";
}

Bureaucrat::Bureaucrat( const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	else
		_grade = grade;
	std::cout << CYAN << _name << ", with a grade of " << _grade << ", was just hired!" << RESET << "\n";
}

Bureaucrat::Bureaucrat( const Bureaucrat &toCopy) : _name(toCopy.getName() + " the Clone") {
	*this = toCopy;
	std::cout << YELLOW << _name << " was cloned!\n" << RESET << "\n";
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << RED << _name << " was fired!" << RESET << "\n";
}

/**/

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
	if (this != &other) {
		_grade = other.getGrade();
		std::cout << YELLOW << _name << " took " << other.getName() << "'s grade!" << RESET << "\n";
	}
	return (*this);
} 

std::ostream &operator<<( std::ostream &os, const Bureaucrat &employee ) {
	os << employee.getName() << ", bureaucrat grade " << employee.getGrade();
	return (os);
}

/**/

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade too high!\n");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade too low!\n");
}

/**/

const std::string Bureaucrat::getName( void ) const {
	return (_name);
}

int Bureaucrat::getGrade( void ) const {
	return (_grade);
}

void Bureaucrat::incrementGrade( int n ) {
	if (_grade - n < 1)
		throw(GradeTooHighException());
	else 
		_grade -= n;
	std::cout << CYAN << _name << " had their grade incremented by " << n << ", now at: " << _grade << RESET << "\n"; 
}

void Bureaucrat::decrementGrade( int n ) {
	if (_grade + n > 150)
		throw(GradeTooLowException());
	else
		_grade += n;
	std::cout << CYAN << _name << " had their grade decremented by " << n << ", now at: " << _grade << RESET << "\n"; 
}

void Bureaucrat::signForm( AForm &form ) {
	if (form.getSigned())
		return ;
	try {
		form.beSigned(*this);
		std::cout << MAGENTA << "The form " << form.getName() << " was signed by " << _name << " !\n" << RESET;
	}
	catch (std::exception &e) {
		std::cout << RED << "The form " << form.getName() << " couldn't be signed by " << _name << " because: ";
		std::cout << e.what() << std::endl << RESET;
	}
}

void Bureaucrat::executeForm( const AForm &form ) {
	try {
		form.execute(*this);
		std::cout << MAGENTA << _name << " executed " << form.getName() << std::endl << RESET;
	}
	catch (std::exception &e) {
		std::cout << RED << "The form " << form.getName() << " couldn't be executed by " << _name << " because: ";
		std::cout << e.what() << std::endl << RESET;
	}
}