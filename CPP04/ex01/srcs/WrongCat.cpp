/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:46:48 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:53:01 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("wrong cat") {
	std::cout << "A new wrong cat  was born!\n";
}

WrongCat::WrongCat( const WrongCat &toCopy ) {
	*this = toCopy;
}

WrongCat &WrongCat::operator=( const WrongCat &other ) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "A wrong cat ran into the forest!\n";
}

void WrongCat::makeSound( void ) const {
	std::cout << "Meow! Meow!\n";
}