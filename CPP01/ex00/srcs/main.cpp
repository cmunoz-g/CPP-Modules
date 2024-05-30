/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:56:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 09:41:45 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	// Zombie created on the heap
	Zombie *zombie_one = newZombie("Mike");
	zombie_one->announce();
	delete zombie_one;
	
	// Zombie created on the stack
	Zombie zombie_two("Frank");
	zombie_two.announce();

	// randomChump
	randomChump("");

	return (0);	
}