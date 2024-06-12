/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:09:51 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 16:33:29 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// We use the cross product of vectors (quantities with both magnitude and direction), which in 2D yield
// a scalar that helps us determine the relative orientation of two vectors.

// For vectors AB and AC, the cross product is AB x AC = (Bx - Ax)(Cy - Ay) - (By - Ay)(Cx - Ax)
// The sign of the cross product indicates the direction of the turn from vector AB to vector AC:
	// Positive: C is to the left of AB
	// Negative: C is to the right of AB
	// Zero: C is colinear to AB (lies in the line extending from A to B)

// For a point P, if all the cross products are positive, P is to the left of each edge when moving in the same
// direction, meaning it is inside the triangle. Similarly, if all cross products are negative, P is inside the triangle.
// When the signs of the cross products vary, P lies outside the triangle.

int crossProduct(Point const one, Point const two, Point const three) {
	Fixed result = (two.getX() - one.getX()) * (three.getY() - one.getY()) - (two.getY() - one.getY()) * (three.getX() - one.getX());

	return (result == 0 ? 0 : (result < 0 ? -1 : 1));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	int cross_ab_ap = crossProduct(a, b, point); 
	int cross_bc_bp = crossProduct(b, c, point);
	int cross_ca_cp = crossProduct(c, a, point);
	
	return (cross_ab_ap == cross_bc_bp && cross_ab_ap == cross_ca_cp);
}