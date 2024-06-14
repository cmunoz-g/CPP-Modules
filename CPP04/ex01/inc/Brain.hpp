/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:45:02 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 09:06:41 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

public:
	Brain( void );
	Brain( const Brain &toCopy);
	Brain &operator=( const Brain &other );
	~Brain( void );

private:
	std::string _ideas[100];

};

#endif