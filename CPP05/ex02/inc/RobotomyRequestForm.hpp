/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:52:41 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 14:00:33 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <random>

class RobotomyRequestForm : public AForm {

public:
	/* Constructors, Destructor, Operators */
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm &toCopy );
	RobotomyRequestForm &operator=( const RobotomyRequestForm &other );
	~RobotomyRequestForm( void );

	/* Exec. function */
	void execute( const Bureaucrat &executor ) const;

private:
	std::string _target;

};

#endif