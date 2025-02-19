/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:05:10 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 11:03:39 by cmunoz-g         ###   ########.fr       */
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

struct Data {
	int number;
	std::string name;
};

class Serializer {
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