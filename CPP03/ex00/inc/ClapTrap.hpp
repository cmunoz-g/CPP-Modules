/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:07:12 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 09:19:47 by camunozg         ###   ########.fr       */
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

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	
};


#endif