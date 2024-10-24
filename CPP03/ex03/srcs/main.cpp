/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:49:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 13:08:33 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond1("James"); 			// String constructor

	std::cout << std::endl;

	diamond1.attack("");					// Attacks no one
	diamond1.attack("Paul");				// Attacks
	diamond1.takeDamage(50);				// Takes damage
	diamond1.takeDamage(65);				// Takes damage, health at 5
	diamond1.beRepaired(100);				// Repaired to 100

	std::cout << std::endl;
	
	diamond1.highFivesGuys();				// High five!

	std::cout << std::endl;
	
	diamond1.guardGate();					// Guarding gates!

	diamond1.guardGate();					// Already in guarding mode.

	diamond1.whoAmI();						// Who is he?

	std::cout << std::endl;

	return (0);
}