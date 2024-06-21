/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:17:12 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/21 09:18:08 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:
	/* Constructors, Destructor, Operator */
	Intern( void );
	Intern( Intern &toCopy );
	Intern &operator=( Intern &other );
	~Intern( void );

	/* Misc. member functions */
	AForm *makeForm( std::string formName, std::string formTarget ) const;
	
	/* Static functions */
	static AForm *makePresident(const std::string target);
	static AForm *makeRobotomy(const std::string target);
	static AForm *makeShrubbery(const std::string target);
};

#endif