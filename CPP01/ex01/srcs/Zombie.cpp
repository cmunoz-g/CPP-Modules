/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:59:10 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 10:17:27 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie( void ) {
	if (_name.empty() == false)
		std::cout << _name << " just died (again)!\n";
	else 
		std::cout << "Nameless Zombie" << " just died (again)!\n";
}

void 	Zombie::announce( void ) const {
	if (_name.empty() == false)
		std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";	
	else
		std::cout << "Nameless Zombie" << ": BraiiiiiiinnnzzzZ...\n";	
}

void	Zombie::zombieName ( std::string name) {
	_name = name;
}