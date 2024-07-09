/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:26:05 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 10:50:36 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
public:
	Array( void );
	Array( const unsigned int n);
	Array( Array &toCopy );
	~Array( void );
	Array &operator=( Array &other );

	T &operator[]( std::size_t index ) const;
	std::size_t size( void ) const;

private:
	T *_arr;
	std::size_t _size;

};

#include "Array.tpp"

#endif