/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:05:13 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 11:46:52 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA ( void ) {}

void HumanA::attack( void ) {
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}
