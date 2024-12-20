/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:04:32 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/16 15:26:27 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void Harl::complain( std::string level ) {
	int i = 0;
	std::string complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; 
	
	while (i < 4) {
		if (complain[i].compare(level) == 0)
			break ;
		i++;
	}
	
	switch(i) {
		case 0:
			(this->debug)();
		case 1:
			(this->info)();
		case 2:
			(this->warning)();
		case 3:
			(this->error)();
			break;
		default: 
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}
