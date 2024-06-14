/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:06:55 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 09:26:49 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal {

public:
	virtual ~AAnimal( void ); 
	virtual void makeSound ( void ) const;
	std::string getType( void ) const;

protected:
	std::string _type;	
	AAnimal( void );
	AAnimal ( const std::string type );
	AAnimal( const AAnimal &toCopy);
	AAnimal &operator=( const AAnimal &other );
	
};

#endif