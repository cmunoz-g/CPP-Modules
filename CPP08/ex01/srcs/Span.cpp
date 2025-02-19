/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:32:06 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 11:25:40 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _N(0) {}

Span::Span( const unsigned int N ) : _N(N) {}

Span::Span( Span &toCopy ) {
	*this = toCopy;
}

Span& Span::operator=( Span &other ) {
	if (this != &other) {
		_N = other.getMax();
		_nbrs = other.getNbrs();
	}
	return (*this);
}

Span::~Span( void ) {}

/**/

void Span::addNumber( const int n ) {
	if (_nbrs.size() == _N) {
		throw (FullVectorException());
	}
	_nbrs.push_back(n);
}

void Span::addNumber( std::vector<int>::iterator start, std::vector<int>::iterator end ) {
	if (_nbrs.size() + std::distance(start, end) > _N) 
		throw(FullVectorException());
	_nbrs.insert(_nbrs.end(), start, end);
}

/**/

std::vector<int> &Span::getNbrs( void ) {
	return (_nbrs);
}

unsigned int Span::getMax( void ) const {
	return (_N);
}

/**/

unsigned int Span::shortestSpan( void ) const {
	if (_nbrs.size() <= 1)
		throw(EmptySpanException());
	
	std::vector<int> temp(_nbrs);
	std::sort(temp.begin(), temp.end());

	long int result = longestSpan();
	long int tempResult;
	
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end() - 1; it++) {
		tempResult = *(it + 1) - *it;
		if (tempResult < result)
			result = tempResult;
	}
	return (result);
}

unsigned int Span::longestSpan( void ) const {
	if (_nbrs.size() <= 1)
		throw(EmptySpanException());
	
	std::vector<int>::const_iterator max = std::max_element(_nbrs.begin(), _nbrs.end());
	std::vector<int>::const_iterator min = std::min_element(_nbrs.begin(), _nbrs.end());
	return (static_cast<long int>(*max) - static_cast<long int>(*min));
}

const char *Span::FullVectorException::what( void ) const throw() {
	return ("Vector is full");
}

const char *Span::EmptySpanException::what( void ) const throw() {
	return ("Span is empty");
}