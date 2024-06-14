/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:36:57 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 09:10:48 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *zoo[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			zoo[i] = new Dog;
		else
			zoo[i] = new Cat;
	}
		
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		zoo[i]->makeSound();
		delete zoo[i];
		std::cout << std::endl;
	}

	return (0);
}