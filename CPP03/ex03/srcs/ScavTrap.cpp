/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:30:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 12:46:41 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("Unnamed_clap_name"), _guardMode(false) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "A new ScavTrap was created, with no name!\n";
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name + "_clap_name"), _guardMode(false) {
	if (name.empty())
		_name = "A Random ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "A new ScavTrap named " << _name << " was created!\n";
}

ScavTrap::ScavTrap( const ScavTrap &toCopy ) {
	*this = toCopy;
	std::cout << "A ScavTrap named " << _name << " was created by copying!\n";
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other ) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_guardMode = other._guardMode;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "A ScavTrap named " << _name << " was destroyed, farewell!\n";
}

void ScavTrap::guardGate( void ) {
	if (_guardMode)
		std::cout << "The ScavTrap " << _name << " was already in Gate keeper mode!\n";
	else {
		_guardMode = true;
		std::cout << "The ScavTrap " << _name << " is now on Gate keeper mode!\n"; 
	}
}

void ScavTrap::attack( const std::string& target ) {
	if (_energyPoints > 0) {
		if (target.empty())
			std::cout << "The ScavTrap " << _name << " attacks no one, causing " << _attackDamage << " points of damage!\n";
		else
			std::cout << "The ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
		_energyPoints--;
	}
	else 
		std::cout << "The ScavTrap " << _name << " doesn't have enough energy to attack, so he takes a nap instead!\n";
}