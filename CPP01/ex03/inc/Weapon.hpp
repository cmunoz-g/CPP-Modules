/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:44:30 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 12:02:06 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <cstdlib>

class Weapon {

public:
	Weapon();
	Weapon( std::string type);
	~Weapon();
	std::string& getType();
	void setType( std::string new_type);
	
private:	
	std::string _type;
	
};


#endif