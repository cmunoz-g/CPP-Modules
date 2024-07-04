/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:34:46 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/29 17:41:54 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data myStruct;
	uintptr_t myPtr;

	myStruct.name = "Random name";
	myStruct.number = 42;

	std::cout << &myStruct << std::endl;

	myPtr = Serializer::serialize(&myStruct);
	Data *toCompare = Serializer::deserialize(myPtr);

	std::cout << toCompare << std::endl;

	if (toCompare == &myStruct)
		std::cout << "Same address!" << std::endl;

	return (0);
}