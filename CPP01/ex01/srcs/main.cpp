/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:56:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/16 14:59:06 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *horde = zombieHorde(4, "Roger");
	
	for (int i = 0; i < 4; i++) {
		std::cout << "Zombie #" << i + 1 << " ";
		horde[i].announce();
	}
	delete[] (horde);
	return (0);	
}