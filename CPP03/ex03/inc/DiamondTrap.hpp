/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:17:02 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 12:36:49 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// The DiamondTrap class inherits from both FragTrap and ScavTrap (which in turn inherit from ClapTrap). 
// Virtual inheritance ensures that only one instance of the common base class is shared among the derived classes,
// solving the diamond problem and preventing redundancy and ambiguity.

// The keyword 'using' determines from which class the different attributes are inherited.

class DiamondTrap: public FragTrap, public ScavTrap {

public:
	using FragTrap::_hitPoints;
	using FragTrap::_attackDamage;
	using ScavTrap::_energyPoints;
	using ScavTrap::attack;
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &toCopy );
	DiamondTrap &operator=( const DiamondTrap &other );
	~DiamondTrap(); 
	void whoAmI( void ) const;

private:
	std::string _name;
};


#endif