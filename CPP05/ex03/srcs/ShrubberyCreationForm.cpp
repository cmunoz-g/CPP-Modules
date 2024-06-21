/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:54:40 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/20 13:53:14 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Random shrubbery form", 145, 137, "Random target") {
	std::cout << CYAN << "A new shrubbery form, with a random target, was dropped at the desk...\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Random shrubbery form", 145, 137, target) {
	std::cout << CYAN << "A new shrubbery form, with " << target << " as target, was dropped at the desk...\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &toCopy ) : AForm(toCopy) {
	*this = toCopy;
	std::cout << YELLOW << getName() << " was photocopied\n" << RESET;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << RED << "The shrubbery creation form \"" << getName() << "\" got thrown in the shredding machine!\n" << RESET;
}

/**/

void ShrubberyCreationForm::execute( const Bureaucrat &executor ) const {
	std::ofstream outFile;
	
	execCheck(executor);
		
	std::string filename = getTarget() + "_shrubbery";
	outFile.open(filename.c_str());
	if (!outFile) {
		std::cerr << "Error while opening the file\n";
		exit(EXIT_FAILURE);
	}
	outFile << ASCII_TREE;
	std::cout << MAGENTA << "A beautiful Ascii Tree was created in " << getTarget() << "_shrubbery!\n" << RESET;
	outFile.close();
}
