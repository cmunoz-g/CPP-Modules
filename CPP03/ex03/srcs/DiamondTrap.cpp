/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:26:08 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 13:06:40 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : _name("Unnamed") {
	std::cout << "A new DiamondTrap was created, with no name!\n\n";
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap() {
	if (name.empty())
		_name = "A Random DiamondTrap";
	else
		_name = name;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "A new DiamondTrap named " << _name << " was created!\n\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap &toCopy ) {
	*this = toCopy;
	std::cout << "A DiamondTrap named " << _name << " was created by copying!\n\n";
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other ) {
	if (this != &other) {
		_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_guardMode = other._guardMode;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "A DiamondTrap named " << _name << " was destroyed, ciao!\n";
}

void DiamondTrap::whoAmI( void ) const {
	std::cout << "My name is... " << _name << " but you can call me " << ClapTrap::_name << "!\n";
}