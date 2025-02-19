/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:16:59 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 10:43:03 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:

	/* Constructors, Destructor, Operators */
	AForm( void );
	AForm( const std::string name, const int sign, const int exec, const std::string target);
	AForm( const AForm &toCopy );
	virtual ~AForm( void );

	AForm &operator=( const AForm &other );

	/* Getters */
	const std::string getName( void ) const;
	bool getSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecGrade( void ) const;
	const std::string getTarget( void ) const;

	/* Misc. member functions */
	void beSigned( const Bureaucrat &signer );
	virtual void execute( const Bureaucrat &executor ) const = 0;
	void execCheck( const Bureaucrat &executor ) const;
	
private:

	/* Exceptions */
	class GradeTooHighException : public std::exception {
		virtual const char *what( void ) const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what( void ) const throw();
	};

	class FormNotSignedException : public std::exception {
		virtual const char *what( void ) const throw();
	};
	
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	const std::string _target;			// We add _target into the Abstract class because of commonality across
										// the derived classes, and because initialization of all attributes is 
										// done at the same place.
};

std::ostream &operator<<( std::ostream &os, const AForm &form );

#endif