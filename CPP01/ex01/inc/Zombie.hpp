/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:27 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 10:17:30 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie() {}
	~Zombie();
	void 	announce( void ) const;
	void	zombieName ( std::string name);
};

Zombie *zombieHorde ( int N, std::string name);

#endif