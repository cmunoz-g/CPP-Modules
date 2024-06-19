/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:35:27 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 13:04:23 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("Random form"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << CYAN << "A new Random form was dropped at the desk...\n" << RESET;
}

Form::Form( const std::string name, const int sign, const int exec ) : _name(name), _signed(false), _signGrade(sign), _execGrade(exec) {
	if (sign < 1 || exec < 1)
		throw(GradeTooHighException());
	else if (sign > 150 || exec > 150)
		throw(GradeTooLowException());
	std::cout << CYAN << "A new form, " << _name << ", was dropped at the desk...\n" << RESET;
}

Form::Form( const Form &toCopy ) : _name(toCopy._name), _signed(toCopy._signed), _signGrade(toCopy._signGrade), _execGrade(toCopy._execGrade){
	*this = toCopy;
	std::cout << YELLOW << _name << " was photocopied\n" << RESET;
}

Form::~Form( void ) {
	std::cout << RED << _name << " got thrown in the shredding machine!\n" << RESET;
}

/**/

Form &Form::operator=( const Form &other ) { // Comprobar si esto debe ser asi (creo que no tiene sentido copiar solo _signed)
	(void)other;
	return (*this);
}

std::ostream &operator<<( std::ostream &os, const Form &form ) {
	os << MAGENTA << "Form name: " << form.getName() << "\n" << "Signed?: " << (form.getSigned() ? "Yes!\n" : "No!\n")
		<< "Signed grade: " << form.getSignGrade() << "\n" << "Execution grade: " << form.getExecGrade() << "\n" << RESET;
	return (os);
}

/**/

const std::string Form::getName( void ) const {
	return (_name);
}

bool Form::getSigned( void ) const {
	return (_signed);
}

int Form::getSignGrade( void ) const {
	return (_signGrade);
}

int Form::getExecGrade( void ) const {
	return (_execGrade);
}

/**/

void Form::beSigned( const Bureaucrat &signer ) {
	if (_signed)
		return ;
	if (signer.getGrade() <= _signGrade)
		_signed = true;
	else
		throw(GradeTooLowException());
}

/**/

const char *Form::GradeTooHighException::what( void ) const throw() {
	return ("The form's grade is too high!\n");
}

const char *Form::GradeTooLowException::what( void ) const throw() {
	return ("The form's grade is too low!\n");
}
