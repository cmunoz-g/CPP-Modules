/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:32 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/19 13:55:53 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

const std::string ASCII_TREE =
"     *\n"
"    /|\\\n"
"   /*|O\\\n"
"  /*/|\\*\\\n"
" /X/O|*\\X\\\n"
"/*/X/|\\X\\*\\\n"
"    |X|\n"
"    |X|\n";

class ShrubberyCreationForm : public AForm {

public:
	/* Constructors, Destructor, Operators */
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm &toCopy );
	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm( void );

	/* Exec. function */
	void execute( const Bureaucrat &executor ) const;

private:
	std::string _target;

};

#endif