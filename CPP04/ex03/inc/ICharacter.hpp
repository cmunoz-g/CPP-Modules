/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:14:02 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:30:11 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter {

public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip( AMateria* m ) = 0;
	virtual void unequip( int idx ) = 0;
	virtual void use( int idx, ICharacter &target ) = 0;
};

#endif