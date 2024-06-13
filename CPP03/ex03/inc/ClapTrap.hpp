/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:07:12 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 10:53:08 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	
public:
	ClapTrap();
	ClapTrap( std::string name );
	~ClapTrap();
	ClapTrap( const ClapTrap &toCopy );
	ClapTrap &operator=( const ClapTrap &other );
	
	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

// The protected access specifier in C++ allows inherited classes to access 
// the members, while still preventing access from outside the class

protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	
};


#endif