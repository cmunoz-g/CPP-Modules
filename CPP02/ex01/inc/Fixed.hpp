/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:42:25 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 12:52:00 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed {
	
public:
	Fixed( void ); 
	Fixed( const Fixed &toCopy ); 
	Fixed( const int number );
	Fixed( const float number );
	
	~Fixed( void ); 
	
	Fixed& operator=(const Fixed &other ); 
	
	int getRawBits( void ) const;
	void setRawBits( int const raw ); 

	float toFloat( void ) const;
	int toInt( void ) const;	
	
private:
	int _value;
	static const int _bits;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif