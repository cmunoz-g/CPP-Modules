/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:49:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 12:10:06 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "FragTrap.hpp"

int main() {
	FragTrap frag1; 					// Default constructor
	FragTrap frag2("James"); 			// String constructor
	FragTrap frag3(frag2);				// Copy constructor
	FragTrap frag4 = frag3;				// Copy assignment operator

	std::cout << std::endl;

	frag1.attack("");					// Attacks no one
	frag1.attack("Paul");				// Attacks
	frag2.takeDamage(50);				// Takes damage
	frag2.takeDamage(70);				// Takes damage, health at 0
	frag2.beRepaired(100);				// Repaired to 100 health.

	std::cout << std::endl;
	
	frag1.highFivesGuys();				// High five!
	frag2.highFivesGuys();
	frag3.highFivesGuys();
	frag4.highFivesGuys();

	std::cout << std::endl;

	return (0);
}