/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:47:28 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:55:20 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat( void );
	WrongCat( const WrongCat &toCopy );
	WrongCat &operator=( const WrongCat &other );
	~WrongCat( void );
	void makeSound( void ) const;

};

#endif