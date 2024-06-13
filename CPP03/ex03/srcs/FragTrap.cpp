/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:05:36 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 12:42:24 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	_name = "Unnamed";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "A new FragTrap was created, with no name!\n";
}

FragTrap::FragTrap( std::string name ) {
	if (name.empty())
		_name = "A Random FragTrap";
	else
		_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "A new FragTrap named " << _name << " was created!\n";
}

FragTrap::FragTrap( const FragTrap &toCopy ) {
	*this = toCopy;
	std::cout << "A FragTrap named " << _name << " was created by copying!\n";
}

FragTrap &FragTrap::operator=( const FragTrap &other ) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap( void ) {
	std::cout << "A FragTrap named " << _name << " was destroyed, so long!\n";
}

void FragTrap::highFivesGuys( void ) {
	std::cout << _name << ": "<< "Hey, up top! Give me a high five!\n";
}