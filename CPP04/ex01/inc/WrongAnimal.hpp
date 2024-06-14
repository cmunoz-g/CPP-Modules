/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:45:14 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:46:36 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:
	WrongAnimal( void );
	WrongAnimal ( const std::string type );
	WrongAnimal( const WrongAnimal &toCopy);
	WrongAnimal &operator=( const WrongAnimal &other );
	virtual ~WrongAnimal( void ); 
	void makeSound ( void ) const;
	std::string getType( void ) const;

protected:
	std::string _type;	
};

#endif