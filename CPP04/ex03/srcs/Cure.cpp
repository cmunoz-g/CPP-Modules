/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:04:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:48:11 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( const Cure &toCopy ) {
	*this = toCopy;
}

Cure &Cure::operator=( const Cure &other ) {
	(void)other;
	return (*this);
}

Cure::~Cure( void ) {}

/**/

Cure *Cure::clone( void ) const {
	return (new Cure);
}

void Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}