/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:17:26 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 08:58:15 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _brain(new Brain) {
	std::cout << "A new dog was born!\n";
}

Dog::Dog( const Dog &toCopy ) {
	*this = toCopy;
	std::cout << "A new dog was born through copying\n";
}

Dog &Dog::operator=( const Dog &other ) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "A dog ran into the forest!\n";
	delete _brain;
}

void Dog::makeSound( void ) const {
	std::cout << "Woof! Woof!\n";
}