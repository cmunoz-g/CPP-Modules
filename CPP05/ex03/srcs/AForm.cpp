/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:35:27 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 10:50:01 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name("Random form"), _signed(false), _signGrade(150), _execGrade(150), _target("Random target") {
	std::cout << CYAN << "A new form was dropped at the desk:\n" << RESET;
}

AForm::AForm( const std::string name, const int sign, const int exec, const std::string target ) : _name(name), _signed(false), _signGrade(sign), _execGrade(exec), _target(target) {
	if (sign < 1 || exec < 1)
		throw(GradeTooHighException());
	else if (sign > 150 || exec > 150)
		throw(GradeTooLowException());
	std::cout << CYAN << "A new form was dropped at the desk:\n" << RESET;
}

AForm::AForm( const AForm &toCopy ) : _name(toCopy._name), _signed(toCopy._signed), _signGrade(toCopy._signGrade), _execGrade(toCopy._execGrade), _target(toCopy._target) {
	*this = toCopy;
	std::cout << YELLOW << _name << " was photocopied\n" << RESET;
}

AForm::~AForm( void ) {
	std::cout << RED << _name << " got thrown in the shredding machine!\n" << RESET;
}

/**/

AForm &AForm::operator=( const AForm &other ) {
	if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

std::ostream &operator<<( std::ostream &os, const AForm &AForm ) {
	os << MAGENTA << "Form name: " << AForm.getName() << "\n" << "Signed?: " << (AForm.getSigned() ? "Yes!\n" : "No!\n")
		<< "Signed grade: " << AForm.getSignGrade() << "\n" << "Execution grade: " << AForm.getExecGrade() << "\nTarget: " << AForm.getTarget() << "\n" << RESET;
	return (os);
}

/**/

const std::string AForm::getName( void ) const {
	return (_name);
}

bool AForm::getSigned( void ) const {
	return (_signed);
}

int AForm::getSignGrade( void ) const {
	return (_signGrade);
}

int AForm::getExecGrade( void ) const {
	return (_execGrade);
}

const std::string AForm::getTarget( void ) const {
	return (_target);
}

/**/

void AForm::beSigned( const Bureaucrat &signer ) {
	if (_signed)
		return ;
	if (signer.getGrade() <= _signGrade)
		_signed = true;
	else
		throw(GradeTooLowException());
}

void AForm::execCheck( const Bureaucrat &executor ) const {
	if (!getSigned())
		throw(FormNotSignedException());
	else if (executor.getGrade() > _execGrade)
		throw(GradeTooHighException());
}

/**/

const char *AForm::GradeTooHighException::what( void ) const throw() {
	return ("The form's grade is too high!\n");
}

const char *AForm::GradeTooLowException::what( void ) const throw() {
	return ("The form's grade is too low!\n");
}

const char *AForm::FormNotSignedException::what( void ) const throw() {
	return ("The form is not signed!\n");
}