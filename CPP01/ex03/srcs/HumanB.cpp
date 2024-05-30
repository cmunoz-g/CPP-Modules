/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:09:18 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 12:17:14 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB ( std::string name ) : _name(name), _weapon(NULL) {}

HumanB::~HumanB ( void ) {}

void HumanB::attack( void ) {
	if (_weapon == NULL)
		std::cout << _name << " attacks with no weapon!\n";
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
}

void HumanB::setWeapon ( Weapon& new_weapon) {
	_weapon = &new_weapon;
}