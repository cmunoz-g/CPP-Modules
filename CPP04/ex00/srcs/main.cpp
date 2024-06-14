/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:36:57 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/13 14:12:25 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl << std::endl;
		
		i->makeSound(); 									
		j->makeSound();										
		meta->makeSound();	
										
		std::cout << std::endl;
		
		delete meta;
		delete j;
		delete i;
	}
	
	std::cout << std::endl;

	// The WrongCat sound is set in WrongCat.cpp as 'Meow! Meow!', but calling the method will output
	// the regular WrongAnimal sound, since it was not declared as virtual and thus the redeclaration
	// in the WrongCat object is not formalized.

	{
		const	WrongAnimal* meta = new WrongAnimal();		
		const	WrongAnimal* wcat = new WrongCat();
		
		std::cout << std::endl;
		std::cout << wcat->getType() << " " << std::endl;

		meta->makeSound();										
		wcat->makeSound();		

		std::cout << std::endl;
									
		delete meta;
		delete wcat;
	}

	return 0;
}