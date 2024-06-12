/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:42:25 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 16:05:30 by camunozg         ###   ########.fr       */
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
	
	Fixed& operator=( const Fixed &other ); 
	
	bool operator>( const Fixed &other ) const;
	bool operator<( const Fixed &other ) const;
	bool operator>=( const Fixed &other ) const;
	bool operator<=( const Fixed &other ) const;
	bool operator==( const Fixed &other ) const;
	bool operator!=( const Fixed &other ) const;
	
	// The operators only take one argument. In the expression a + b, the operator is called onto 'a' (implicitly '*this') and 'b' is passed as the explicit
	// parameter to the operator.
	
	Fixed operator+( const Fixed &other ) const;
	Fixed operator-( const Fixed &other ) const;
	Fixed operator*( const Fixed &other ) const;
	Fixed operator/( const Fixed &other ) const;
	
	Fixed operator++( ); 		// Pre-increment '++a'
	Fixed operator++( int ); 	// Post-increment 'a++'
	Fixed operator--( ); 		// Pre-decrement '--a'
	Fixed operator--( int ); 	// Post-decrement 'a--'

	int getRawBits( void ) const;
	void setRawBits( int const raw ); 

	float toFloat( void ) const;
	int toInt( void ) const;	

	static Fixed &min( Fixed &a, Fixed &b );
	static Fixed &max( Fixed &a, Fixed &b );
	const static Fixed &min( const Fixed &a, const Fixed &b);
	const static Fixed &max( const Fixed &a, const Fixed &b);
	
private:
	int _value;
	static const int _bits;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif