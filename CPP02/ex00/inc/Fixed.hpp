/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:42:25 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 11:12:20 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	
public:
	Fixed( void ); // Constructor
	~Fixed( void ); // Destructor
	Fixed( const Fixed &toCopy); // Copy Constructor
	Fixed& operator=(const Fixed &other); // Copy Assignment Operator Overload
	int getRawBits( void ) const;
	void setRawBits( int const raw ); 
	
private:
	int _value;
	static const int _bits;

};

#endif