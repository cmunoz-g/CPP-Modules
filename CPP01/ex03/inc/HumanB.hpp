/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:53:41 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 12:17:05 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP 
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:
	void attack( void );
	void setWeapon ( Weapon& new_weapon );
	HumanB( std::string name );
	~HumanB( void );

private:
	std::string _name;
	Weapon*		_weapon;

};


#endif