/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:17:02 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 12:28:17 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// The DiamondTrap class inherits from both FragTrap and ScavTrap (which in turn inherit from ClapTrap). 
// Virtual inheritance ensures that only one instance of the common base class is shared among the derived classes,
// solving the diamond problem and preventing redundancy and ambiguity (see how FragTrap and ScavTrap inherit)

// The keyword 'using' determines from which class the different attributes are inherited.

class DiamondTrap: public FragTrap, public ScavTrap {

public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &toCopy );
	DiamondTrap &operator=( const DiamondTrap &other );
	~DiamondTrap(); 
	void whoAmI( void ) const;
	using ScavTrap::attack;

private:
	std::string _name;
	using FragTrap::_hitPoints;
	using FragTrap::_attackDamage;
	using ScavTrap::_energyPoints;
};


#endif