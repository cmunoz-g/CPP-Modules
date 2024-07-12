/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:46:49 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/12 10:40:50 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	// Uses the iterators from the underlying class (those from deque)
	typedef typename std::stack<T>::container_type::iterator iterator; 
	typedef typename std::stack<T>::container_type::const_iterator const_iterator; 
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator; 
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator; 
	
	MutantStack( void );
	MutantStack( const MutantStack &toCopy );
	~MutantStack( void );

	MutantStack &operator=( const MutantStack &other );

	// Iterator to the first element
	iterator begin( void );
	const_iterator begin() const;
	
	// Iterator to the last element
	iterator end( void );
	const_iterator end( void ) const;
	
	// Reverse iterator to the last element
	reverse_iterator rbegin( void );
	const_reverse_iterator rbegin( void ) const;
	
	// Reverse iterator to the first element
	reverse_iterator rend( void );
	const_reverse_iterator rend( void ) const; 

}; 

#include "MutantStack.tpp"

#endif