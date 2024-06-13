/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:49:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 12:44:24 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond1; 					// Default constructor
	DiamondTrap diamond2("James"); 			// String constructor
	DiamondTrap diamond3(diamond2);			// Copy constructor
	DiamondTrap diamond4 = diamond3;		// Copy assignment operator

	std::cout << std::endl;

	diamond1.attack("");					// Attacks no one
	diamond1.attack("Paul");				// Attacks
	diamond2.takeDamage(50);				// Takes damage
	diamond2.takeDamage(70);				// Takes damage, health at 0
	diamond2.beRepaired(100);				// Repaired to 100 health.

	std::cout << std::endl;
	
	diamond1.highFivesGuys();				// High five!
	diamond2.highFivesGuys();
	diamond3.highFivesGuys();
	diamond4.highFivesGuys();

	std::cout << std::endl;
	
	diamond1.guardGate();					// Guarding gates!
	diamond2.guardGate();
	diamond3.guardGate();
	diamond4.guardGate();

	diamond1.guardGate();					// Already in guarding mode.

	std::cout << std::endl;

	return (0);
}