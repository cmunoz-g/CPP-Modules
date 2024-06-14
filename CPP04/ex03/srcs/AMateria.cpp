/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:57 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 13:09:53 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("none") {}

AMateria::AMateria( const std::string &type ) : _type(type) {
	if (_type.empty())
		_type = "unknown";
}

AMateria::AMateria( const AMateria &toCopy) {
	*this = toCopy;
}

AMateria &AMateria::operator=(const AMateria &other ) {
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria( void ) {}

/**/

const std::string &AMateria::getType( void ) const {
	return (_type);
}

void AMateria::use( ICharacter &target ) {
	std::cout << "* uses their materia '" << _type << "' against " << target.getName() << " *\n";
} 
