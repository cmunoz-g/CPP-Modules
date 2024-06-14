/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:10:03 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:44:09 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("Just a random animal") {
	std::cout << "A new animal was born!\n";
}

Animal::Animal( const std::string type ) {
	if (type.empty())
		_type = "Unspecified animal";
	else
		_type = type;
	std::cout << "A new animal was born!\n";
}

Animal::Animal( const Animal &toCopy ) {
	*this = toCopy; 
	std::cout << "A new animal was born through copying!\n";
}

Animal &Animal::operator=( const Animal &other ) {
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "An animal ran into the forest!\n";
}

std::string Animal::getType( void ) const {
	return (_type);
}

void Animal::makeSound( void ) const {
	std::cout << "* Random animal noises *\n";
}