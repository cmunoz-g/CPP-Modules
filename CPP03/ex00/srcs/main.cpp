/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:49:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 10:05:17 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clap1; 					// Default constructor
	ClapTrap clap2("Mike"); 			// String constructor
	ClapTrap clap3(clap2);				// Copy constructor
	ClapTrap clap4 = clap3;				// Copy assignment operator

	std::cout << std::endl;

	clap1.attack("");					// Attacks no one
	clap1.attack("Peter");				// Attacks
	clap2.takeDamage(5);				// Takes damage
	clap2.takeDamage(7);				// Takes damage, health at 0
	clap2.beRepaired(10);				// Repaired to full health (10)
	clap2.beRepaired(1);				// Trying to repair while at full health.

	std::cout << std::endl;
	
	for (int i = 0; i < 10; i++)		// Attacking until no energy is left
		clap3.attack("John");

	std::cout << std::endl;
	
	clap3.attack("John");				// Attacking with no energy
	clap3.takeDamage(5);
	clap3.beRepaired(5);				// Trying to repair with no energy.

	std::cout << std::endl;
	
	return (0);
}