/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:00:14 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 16:38:43 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
	
	//Point inside the triangle
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point p(1, 2);

    if (bsp(a, b, c, p)) {
        std::cout << "Point is inside the triangle." << std::endl;
    } else {
        std::cout << "Point is outside the triangle." << std::endl;
    }

    return 0;
}

/*
// Point outside the triangle 

Point a(0, 0);
Point b(10, 0);
Point c(0, 10);
Point p(-1, 2);

// Point in a vertex (outside)

Point a(0, 0);
Point b(10, 0);
Point c(0, 10);
Point p(10, 0);

// Point along an edge (outside)

Point a(0, 0);
Point b(10, 0);
Point c(0, 10);
Point p(10, 4);

*/