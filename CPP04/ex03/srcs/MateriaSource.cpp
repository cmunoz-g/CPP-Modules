/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:02:57 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/17 11:54:27 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	this->initInventory();
}

MateriaSource::MateriaSource( const MateriaSource &toCopy ) {
	*this = toCopy;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other ) {
	if (this != &other) {
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

MateriaSource::~MateriaSource( void ) {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

/**/

void MateriaSource::initInventory( void ) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

AMateria *MateriaSource::getMateria( int idx ) const {
	return (_inventory[idx]);
}

void MateriaSource::learnMateria( AMateria *materia ) {
	bool learned = false;
	int i = 0;

	while (i < 4 && !learned) {
		if (_inventory[i] == NULL) {
			_inventory[i] = materia;
			std::cout << materia->getType() << " was learned at slot " << i << "\n";
			learned = true;
		}
		i++;
	}
	if (!learned) {
		std::cout << "The inventory is full!\n";
		delete materia;
	}
}

AMateria *MateriaSource::createMateria( const std::string &type ) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			return (_inventory[i]->clone());
		}
	}
	return (NULL);
}
