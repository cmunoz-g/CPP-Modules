/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:49:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 11:49:35 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*

When an object of a derived class (ScavTrap) is created, the constructor of its base class (ClapTrap) is called first.
This ensures that the base class part of the derived class object is properly initialized before the derived class constructor runs.


In the ScavTrap constructors, the ClapTrap constructors are not explicitly called, 
so the default behavior is to call the default constructor of the base class.

*/

int main() {
	ScavTrap scav1; 					// Default constructor
	ScavTrap scav2("Mike"); 			// String constructor
	ScavTrap scav3(scav2);				// Copy constructor
	ScavTrap scav4 = scav3;				// Copy assignment operator

	std::cout << std::endl;

	scav1.attack("");					// Attacks no one
	scav1.attack("Peter");				// Attacks
	scav2.takeDamage(50);				// Takes damage
	scav2.takeDamage(70);				// Takes damage, health at 0
	scav2.beRepaired(100);				// Can't be repaired, health at 0

	std::cout << std::endl;
	
	scav1.guardGate();					// Guarding gates!
	scav2.guardGate();
	scav3.guardGate();
	scav4.guardGate();

	scav1.guardGate();					// Already in guarding mode.

	std::cout << std::endl;

	return (0);
}