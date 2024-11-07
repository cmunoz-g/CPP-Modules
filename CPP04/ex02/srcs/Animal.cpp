/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:10:03 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 09:23:06 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal( void ) : _type("Just a random animal") {
	std::cout << "A new animal was born!\n";
}

AAnimal::AAnimal( const std::string type ) {
	if (type.empty())
		_type = "Unspecified animal";
	else
		_type = type;
	std::cout << "A new animal was born!\n";
}

AAnimal::AAnimal( const AAnimal &toCopy ) {
	*this = toCopy; 
	std::cout << "A new animal was born through copying!\n";
}

AAnimal &AAnimal::operator=( const AAnimal &other ) {
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal( void ) {
	std::cout << "An animal ran into the forest!\n";
}

std::string AAnimal::getType( void ) const {
	return (_type);
}
