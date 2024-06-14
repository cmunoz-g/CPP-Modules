/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:12:31 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:25:46 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria {

public:
	Cure( void );
	Cure( const Cure &toCopy );
	Cure &operator=( const Cure &other );
	~Cure( void );
	
	Cure* clone( void ) const;
	void use( ICharacter& target );

};

#endif