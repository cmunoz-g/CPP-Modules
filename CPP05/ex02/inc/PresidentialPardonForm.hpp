/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:51:28 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/20 13:43:59 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
	/* Constructors, Destructor, Operators */
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm &toCopy );
	PresidentialPardonForm &operator=( const PresidentialPardonForm &other );
	~PresidentialPardonForm( void );

	/* Exec. function */
	void execute( const Bureaucrat &executor ) const;

private:
	std::string _target;

};

#endif