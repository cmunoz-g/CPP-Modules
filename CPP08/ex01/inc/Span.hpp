/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:22:09 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 13:44:24 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Span {

public:
	Span( void );
	Span( const unsigned int N );
	Span( Span &toCopy );
	~Span( void );
	Span &operator=( Span &other );

	void addNumber( const int n );
	void addNumber( std::vector<int>::iterator start, std::vector<int>::iterator end );
	std::vector<int> &getNbrs( void );
	unsigned int getMax( void ) const ;
	unsigned int shortestSpan( void ) const;
	unsigned int longestSpan( void ) const;

private:
	unsigned int _N;
	std::vector<int> _nbrs;

	class FullVectorException : public std::exception {
		public:
			const char *what( void ) const throw();
	};

	class EmptySpanException : public std::exception {
		public:
			const char *what( void ) const throw();
	};
	
};

#endif