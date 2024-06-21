/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:46:54 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 12:54:26 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define CYAN "\x1b[36m"
#define YELLOW "\x1b[33m"
#define MAGENTA "\x1b[35m"

class AForm;

class Bureaucrat {

public:

	/* Constructors, Destructor, Operators */
	Bureaucrat( void );
	Bureaucrat( const std::string name, int grade );
	Bureaucrat( const Bureaucrat &toCopy);
	~Bureaucrat( void );

	Bureaucrat &operator=( const Bureaucrat &other);

	/* Getters*/
	const std::string getName( void ) const;
	int getGrade( void ) const;
	
	/* Misc. member functions */
	void incrementGrade( int n );
	void decrementGrade( int n );
	void signForm( AForm &form );
	void executeForm( const AForm &form );
	
private:

	/* Exception classes */
		// We include classes that inherit from std::exception in order to override the what() method.
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what( void ) const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what( void ) const throw();
	};

	const std::string _name;
	int _grade;
	
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &employee );

#endif