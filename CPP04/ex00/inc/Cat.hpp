/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:31:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 13:40:58 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat( void );
	Cat( const Cat &toCopy );
	Cat &operator=( const Cat &other );
	~Cat( void );
	void makeSound( void ) const;

};