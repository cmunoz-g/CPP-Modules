/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:49:18 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 11:46:14 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP 
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

public:
	void attack( void );
	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );

private:
	std::string _name;
	Weapon&		_weapon;

};


#endif