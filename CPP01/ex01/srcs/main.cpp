/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:56:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 10:09:32 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *horde = zombieHorde(4, "Roger");
	
	for (int i = 0; i < 4; i++)
		horde[i].announce();
	delete[] (horde);
	return (0);	
}