/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:58:06 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:48:19 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( const Ice &toCopy ) {
	*this = toCopy;
}

Ice &Ice::operator=( const Ice &other ) {
	(void)other;
	return (*this);
}

Ice::~Ice( void ) {}

/**/

Ice *Ice::clone( void ) const {
	return (new Ice);
}

void Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
