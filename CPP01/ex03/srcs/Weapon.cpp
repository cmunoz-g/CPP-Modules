/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:56:10 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 12:06:58 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {} 

Weapon::Weapon ( std::string type ) : _type(type) {}

Weapon::~Weapon() {}

std::string& Weapon::getType( void ) {
	std::string &weaponREF = _type;
	return (weaponREF);
}

void Weapon::setType ( std::string new_type) {
	_type = new_type;
}