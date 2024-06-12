/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:26:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/07 09:52:14 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
public:
	Harl( void );
	~Harl( void );
	void complain ( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void (Harl::*ptr[4])(void);
};

#endif