/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:06:55 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 08:56:11 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {

public:
	Animal( void );
	Animal ( const std::string type );
	Animal( const Animal &toCopy);
	Animal &operator=( const Animal &other );
	
	// Destructor is set as virtual to ensure correct sequence of object destruction.
	virtual ~Animal( void ); 
	virtual void makeSound ( void ) const;
	std::string getType( void ) const;

protected:
	std::string _type;	
};

#endif