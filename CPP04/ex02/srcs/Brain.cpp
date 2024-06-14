/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:47:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 09:07:48 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "A brain was just created!\n";
}

Brain::Brain( const Brain &toCopy ) {
	*this = toCopy;
	std::cout << "A brain was just created by copying!\n";
}

Brain &Brain::operator=( const Brain &other ) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain( void ) {
	std::cout << "A brain just disappeared!\n";
}
