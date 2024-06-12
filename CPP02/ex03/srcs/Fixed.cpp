/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:58:34 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 16:05:34 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

/* Constructors / Destructor */

Fixed::Fixed( void ) : _value(0) {}

Fixed::Fixed( const Fixed &toCopy) {
	*this = toCopy;
}

Fixed::Fixed( const int number) : _value(number << _bits) {}

Fixed::Fixed( const float number) : _value(roundf(number * (1 << _bits))) {}

Fixed::~Fixed( void ) {}

/* Comparison operators */ 

bool Fixed::operator>( const Fixed &other) const {
	return (_value > other._value); 
}

bool Fixed::operator<( const Fixed &other) const {
	return (_value < other._value); 
}

bool Fixed::operator>=( const Fixed &other) const {
	return (_value >= other._value); 
}

bool Fixed::operator<=( const Fixed &other) const {
	return (_value <= other._value); 
}

bool Fixed::operator==( const Fixed &other) const {
	return (_value == other._value); 
}

bool Fixed::operator!=( const Fixed &other) const {
	return (_value != other._value); 
}

/* Arithmetic operators */

Fixed Fixed::operator+( const Fixed &other ) const {
	Fixed res;
	
	res._value = _value + other._value;
	return (res);
}

Fixed Fixed::operator-( const Fixed &other ) const {
	Fixed res;
	
	res._value = _value - other._value;
	return (res);
}

Fixed Fixed::operator*(const Fixed &other ) const {
	Fixed res;

	res._value = (static_cast<long>(_value) * static_cast<long>(other._value)) >> _bits;
	return (res);
}

Fixed Fixed::operator/( const Fixed &other ) const {
	Fixed res;

	if (other._value == 0) {
		std::cerr << "Division by zero\n";
		exit(EXIT_FAILURE);
	}
	res._value = (static_cast<long>(_value) << _bits) / (static_cast<long>(other._value));
	return (res);	
}

/* Increment / Decrements */

Fixed Fixed::operator++( void ) {
	_value++;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	_value++;
	return (tmp);
}

Fixed Fixed::operator--( void ) {
	_value--;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	_value--;
	return (tmp);
}

/* Min. / Max. */

Fixed &Fixed::min( Fixed &a, Fixed &b) {
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b) {
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b) {
	if (a._value < b._value)
		return (b);
	else
		return (a);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b) {
	if (a._value < b._value)
		return (b);
	else
		return (a);
}

/* Misc. member functions */

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		_value = other.getRawBits();
	}
	return (*this);
}


int Fixed::getRawBits( void ) const {
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

/* << overload */

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	return (os << fixed.toFloat());
}
