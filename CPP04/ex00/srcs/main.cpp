/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:36:57 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/24 13:18:49 by cmunoz-g         ###   ########.fr       */
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

		const Animal w = *j;

		std::cout << std::endl;
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl << std::endl;
		
		std::cout << "Animal i: ";
		i->makeSound();

		std::cout << "Animal j: ";						
		j->makeSound();	

		std::cout << "Animal w: ";			
		w.makeSound();

		std::cout << "Animal meta: ";
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