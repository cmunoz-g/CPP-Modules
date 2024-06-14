/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:46:03 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:46:05 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("Just a random wrong animal") {
	std::cout << "A new wrong animal was born!\n";
}

WrongAnimal::WrongAnimal( const std::string type ) {
	if (type.empty())
		_type = "Unspecified wrong animal";
	else
		_type = type;
	std::cout << "A new wrong animal was born!\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal &toCopy ) {
	*this = toCopy; 
	std::cout << "A new wrong animal was born through copying!\n";
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ) {
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "An wrong animal ran into the forest!\n";
}

std::string WrongAnimal::getType( void ) const {
	return (_type);
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "* Random wrong animal noises *\n";
}