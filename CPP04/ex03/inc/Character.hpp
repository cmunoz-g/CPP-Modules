/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:30:08 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:53:43 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {

public:
	Character( void );
	Character( std::string name);
	Character( const Character &toCopy);
	Character &operator=( const Character &other );
	~Character( void );

	const std::string &getName( void ) const;
	AMateria *getMateria( int idx ) const;
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );

private:
	void initInventory( void );
	std::string _name;
	AMateria *_inventory[4];

};

#endif