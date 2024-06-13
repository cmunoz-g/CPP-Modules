/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:22:22 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 11:59:37 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap &toCopy );
	ScavTrap &operator=( const ScavTrap &other );
	~ScavTrap(); 
	void attack( const std::string& target );
	void guardGate( void );
	
private:
	bool _guardMode;
};


#endif