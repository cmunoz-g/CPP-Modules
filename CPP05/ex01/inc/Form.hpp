/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:16:59 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 13:04:16 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	/* Constructors, Destructor, Operators */
	Form( void );
	Form( const std::string name, const int sign, const int exec );
	Form( const Form &toCopy );
	~Form( void );

	Form &operator=( const Form &other );

	/* Getters */
	const std::string getName( void ) const;
	bool getSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecGrade( void ) const;

	/* Misc. member functions */
	void beSigned( const Bureaucrat &signer );
	
private:

	/* Exceptions */
	class GradeTooHighException : public std::exception {
		virtual const char *what( void ) const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what( void ) const throw();
	};
	
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	
};

std::ostream &operator<<( std::ostream &os, const Form &form );


#endif