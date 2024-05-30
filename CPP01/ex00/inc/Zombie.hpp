/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:27 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 09:36:46 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie( std::string name );
	~Zombie();
	void 	announce( void ) const;	
};

Zombie *newZombie( std::string name );
void 	randomChump( std::string name);

#endif