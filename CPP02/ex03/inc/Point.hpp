/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:59:31 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 16:07:52 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

public:
	Point( void );
	Point( const float toX, const float toY );
	Point( const Point &toCopy);
	Point& operator=( const Point &other );
	~Point( void );
	Fixed getX( void ) const;
	Fixed getY( void ) const;

private:
	const Fixed _x;
	const Fixed _y;
	
};

#endif