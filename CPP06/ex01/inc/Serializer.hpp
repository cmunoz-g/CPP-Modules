/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:05:10 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/29 17:43:56 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

// Implement a class Serializer, who will not be initializable by the user by any way,
// with the following static methods:
// uintptr_t serialize(Data* ptr);
// It takes a pointer and converts it to the unsigned integer type uintptr_t.
// Data* deserialize(uintptr_t raw);
// It takes an unsigned integer parameter and converts it to a pointer to Data.
// Write a program to test that your class works as expected.
// You must create a non-empty (it means it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
// Do not forget to turn in the files of your Data structure.

struct Data {	// Deberia poner esto en otro archivo .hpp?
	int number;
	std::string name;
};

class Serializer { // Revisar si hace falta tener el = overload y el copy constructor
public:
	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw);
	
private:
	Serializer( void );
	~Serializer( void );
	Serializer( Serializer &toCopy );
	Serializer &operator=( Serializer &other );

};

#endif