/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:58:34 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 12:27:57 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed &toCopy) {
	std::cout << "Copy constructor called\n";
	*this = toCopy;
}

// Shifting the int by _bits is equivalent to multiplying it by 2 to the _bits, converting it to the fp representation.

Fixed::Fixed( const int number) : _value(number << _bits) { 
	std::cout << "Int constructor called\n";
}

// In the case of the float, we cannot perform bitwise operations (as those are meant for ints due to the different
// binary representation of decimal numbers), so we multiply it by 2 to the _bits (1 << _bits), effectively performing the same operation
// done to the int, but ensuring we maintaing the fractional part of the number.

Fixed::Fixed( const float number) : _value(roundf(number * (1 << _bits))) {
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		_value = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << _bits));
}

int	Fixed::toInt( void ) const {
	return (_value >> _bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	return (os << fixed.toFloat());
}
