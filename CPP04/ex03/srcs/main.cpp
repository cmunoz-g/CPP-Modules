/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:24:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/17 12:08:21 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	// The line below demonstrates polymorphism. src is a pointer to IMateriaSource, but it actually points to a MateriaSource object.
	// This means you can use src to call learnMateria and createMateria on a MateriaSource object without knowing that it is specifically a MateriaSource.

    IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());						// Repeated types can be learned, and will be put in the next possible free slot.
	src->learnMateria(new Ice());
	std::cout << std::endl;

	src->learnMateria(new Ice());						// Trying to equip too many Materia.
	std::cout << std::endl;
	
	ICharacter* me = new Character("me");
	std::cout << std::endl;
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");					// Trying to create a non-defined type results in a NULL Materia pointer, which gets rejected while trying to equip
	me->equip(tmp);
	std::cout << std::endl;
	
	me->equip(new Ice());								// Characters can equip types directly.
	me->equip(new Cure());
	std::cout << std::endl;

	me->equip(new Cure());								// Trying to equip while the inventory is full.
	
	Character *deMe = dynamic_cast<Character*>(me);		// Saving the address of the materia to avoid memory leaks.
	AMateria *uneq = deMe->getMateria(3);
	
	me->unequip(3);										// Unequipping
	me->equip(new Cure());								// Equipping again
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	delete uneq;

    return 0;
}