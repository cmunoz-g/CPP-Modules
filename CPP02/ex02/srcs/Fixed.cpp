/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:58:34 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 14:43:02 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

/* Constructors / Destructor */

Fixed::Fixed( void ) : _value(0) {
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed &toCopy) {
	//std::cout << "Copy constructor called\n";
	*this = toCopy;
}

Fixed::Fixed( const int number) : _value(number << _bits) { 
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed( const float number) : _value(roundf(number * (1 << _bits))) {
	//std::cout << "Float constructor called\n";
}

Fixed::~Fixed( void ) {
	//std::cout << "Destructor called\n";
}

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

// When it comes to multiplication, operations result in the change of scale (from '2 to the _bits' to '2 to the 2 * _bits'), so we must shift the product right by _bits.
// In divisions, we must shift the numerator left by '2 to the _bits' in order to preserve the fractional bits during the operation.

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
	//std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		_value = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called\n";
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
