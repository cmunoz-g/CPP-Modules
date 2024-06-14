/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:05:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 13:24:39 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("unnamed") {
	this->initInventory();
}

Character::Character( std::string name ) : _name(name) {
	if (_name.empty())
		_name = "unnamed";
	this->initInventory();
	std::cout << "Hi! I'm " << _name << "\n";
}

Character::Character( const Character &toCopy ) {
	*this = toCopy;
}

Character &Character::operator=( const Character &other ) {
	if (this != &other) {
		_name = other.getName();
		for (int i = 0; i < 4; i++) {
			if (other.getMateria(i)) {
				delete _inventory[i]; 
				_inventory[i] = other.getMateria(i)->clone();
			}
			else {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character( void ) { 
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << _name << ": Bye!\n";
}

/**/

void Character::initInventory( void ) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

const std::string &Character::getName( void ) const {
	return (_name);
}

AMateria *Character::getMateria( int idx ) const {
	return (_inventory[idx]);
}

void Character::equip( AMateria *m ) { // Should I check for m to be null?
	bool equipped = false;
	int i = 0;

	if (!m)
		std::cout << "Can't equip that!\n";
	else {
		while (i < 4 && !equipped) {
			if (_inventory[i] == NULL) {
				_inventory[i] = m->clone();
				std::cout << m->getType() << " was equipped by " << _name << " at slot " << i << "\n";
				equipped = true;
			}
			i++;
		}
		if (!equipped)
			std::cout << "The inventory is full, try unequipping one slot!\n";
	}
}

void Character::unequip( int idx ) { // Whats going on with this _inventory memory??
	if (idx < 0 || idx > 4)
		std::cout << "Wrong index!\n";
	else if (_inventory[idx]) {
		_inventory[idx] = NULL;
		std::cout << "Unequipped the materia at slot " << idx << "\n"; 
	}
	else
		std::cout << "There is nothing at that slot!\n";
}

void Character::use( int idx, ICharacter &target ) {
	if (idx < 0 || idx > 4)
		std::cout << "Wrong index!\n";
	else if (!_inventory[idx])
		std::cout << "There is nothing at that slot!\n";
	else
		_inventory[idx]->use(target);
}
