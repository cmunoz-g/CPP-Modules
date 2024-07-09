/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:25:56 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 10:50:53 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _arr(), _size(0) {}

template <typename T>
Array<T>::Array( const unsigned int n) : _arr(new T[n]()), _size(n) {}
 
template <typename T>
Array<T>::Array( Array &toCopy ) : _arr() {
	*this = toCopy;
}

template <typename T>
Array<T>::~Array( void ) {
	delete[] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=( Array &other ) {
	if (this != other) {
		delete[] _arr;
		_arr = new T[other.size()];
		for (int i = 0; i < other.size(); i++) 
			_arr[i] = other[i];
		_size = other.size();
	}
	return (this);
}

template <typename T>
T &Array<T>::operator[]( std::size_t index ) const {
	if (index >= _size)
		throw std::out_of_range("Index is out of range");
	return (_arr[index]);
}

template <typename T>
std::size_t Array<T>::size( void ) const {
	return (_size);
}
