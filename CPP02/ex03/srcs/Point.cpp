/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:04:25 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 16:38:46 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point(const float toX, const float toY) : _x(toX), _y(toY) {}
	
Point::Point( const Point &toCopy) {
	*this = toCopy;
}

Point &Point::operator=( const Point &other ) {
	if (this != &other) {
		const_cast<Fixed &>(_x) = other._x;
        const_cast<Fixed &>(_y) = other._y;
	}
	return (*this);
}
	
Point::~Point( void ) {}

Fixed Point::getX( void ) const {
	return (_x);
}

Fixed Point::getY( void ) const {
	return (_y);
}

	