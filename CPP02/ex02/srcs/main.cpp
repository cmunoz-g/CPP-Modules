/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:26:00 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 10:17:00 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << "is " << a << " smaller than " << b << "?: " << (a < b) << std::endl;
	std::cout << "is " << a << " greater than " << b << "?: " << (a > b) << std::endl;
	std::cout << "is " << a << " different than " << b << "?: " << (a != b) << std::endl;
	std::cout <<  a << " divided by " << b << " is " << (a / b) << std::endl;
	std::cout <<  a << " minus " << b << " is " << (a - b) << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	return (0);
}


