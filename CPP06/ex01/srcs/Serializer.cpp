/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:20:07 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/04 10:25:05 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::Serializer( Serializer &toCopy ) {
	(void)toCopy;
}

Serializer &Serializer::operator=( Serializer &other ) {
	(void)other;
	return (*this);
}

Serializer::~Serializer( void ) {}

/**/

// Reinterpret cast does not change the bit pattern of the data, it just interprets 
// it as another type.

uintptr_t Serializer::serialize( Data *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize( uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
