/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:26:00 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 10:15:01 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	
	return 0;
}

/*
Default constructor called        		For Fixed a;
Int constructor called            		For Fixed const b(10);
Float constructor called          		For Fixed const c(42.42f);
Copy constructor called           		For Fixed const d(b);
Copy assignment operator called   		Inside copy constructor for d
getRawBits member function called 		Inside copy assignment for d
Float constructor called          		For temporary Fixed(1234.4321f)
Copy assignment operator called   		Assign temporary to a
getRawBits member function called 		Inside copy assignment operator
Destructor called                 		Destructor for temporary Fixed(1234.4321f)
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called

*/