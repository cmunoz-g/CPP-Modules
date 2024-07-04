/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:38:00 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/04 11:38:36 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABase.hpp"
#include "BBase.hpp"
#include "CBase.hpp"

Base *generate( void ) {
	srand(time(NULL));
	int n = rand() % 3;										// Any number modulo 3 will either have 0, 1 or 2 as remainder.

	if (n == 1) {
		std::cout << "A Base was randomly generated" << std::endl;;
		return (new A);
	}
	else if (n == 2) {
		std::cout << "B Base was randomly generated" << std::endl;;
		return (new B);
	}
	else {
		std::cout << "C Base was randomly generated" << std::endl;
		return (new C);
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Base of type A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "Base of type B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "Base of type C" << std::endl;
	}
	else 
		std::cout << "Unknown base" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Base of type A" << std::endl;
	} catch (const std::exception &e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Base of type B" << std::endl;
	} catch (const std::exception &e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Base of type C" << std::endl;
	} catch (const std::exception &e) {}
}

// Dynamic casting serves as a way to check if a downcast (from a class Base to
// one of its derived classes) can be performed.
// When failing to cast to a pointer, it returns a NULL pointer.
// When failing to cast to a reference, it throws an exception.

int main() {
	Base *base = generate();
	
	identify(base);
	
	identify(*base);
	
	delete base;
	return (0);
}