/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:09:12 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:25:52 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria {

public:
	Ice( void );
	Ice( const Ice &toCopy );
	Ice &operator=( const Ice &other );
	~Ice( void );
	
	Ice* clone( void ) const;
	void use( ICharacter& target );

};

#endif