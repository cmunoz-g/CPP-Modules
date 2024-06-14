/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:47:25 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 13:05:06 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include "ICharacter.hpp"

class AMateria {
	
public:
	AMateria( void );
	AMateria( const std::string &type );
	AMateria( const AMateria &toCopy);
	AMateria &operator=(const AMateria &other );
	virtual ~AMateria( void );

	const std::string &getType( void ) const;
	// The pure virtual function 'clone' makes the class abstract (cannot be instantiated).
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter &target );
	
protected:
	std::string _type;

};

#endif