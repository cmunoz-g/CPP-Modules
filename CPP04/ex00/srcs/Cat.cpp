/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:33:24 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:43:06 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "A new cat was born!\n";
}

Cat::Cat( const Cat &toCopy ) {
	*this = toCopy;
}

Cat &Cat::operator=( const Cat &other ) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "A cat ran into the forest!\n";
}

void Cat::makeSound( void ) const {
	std::cout << "Meow! Meow!\n";
}