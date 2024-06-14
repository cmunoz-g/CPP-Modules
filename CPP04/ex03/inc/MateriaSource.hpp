/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:37:06 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/14 12:59:07 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

/*
By inheriting IMateriaSource, MateriaSource guarantees that it will provide implementations for learnMateria and createMateria.
This allows MateriaSource to be used polymorphically through an IMateriaSource pointer or reference.
*/

class MateriaSource : public IMateriaSource {

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &toCopy );
	MateriaSource &operator=( const MateriaSource &other );
	~MateriaSource( void );
	
	void learnMateria( AMateria *materia );
	AMateria *createMateria( const std::string &type );
	AMateria *getMateria( int idx ) const;

private:
	void initInventory( void );
	AMateria *_inventory[4];

};

#endif