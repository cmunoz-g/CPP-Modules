/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:36:45 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/27 10:13:23 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

class PmergeMe {

public:
	PmergeMe();
	PmergeMe( int argc, char *argv[] );
	PmergeMe( const PmergeMe &toCopy );
	~PmergeMe();

	PmergeMe &operator=( const PmergeMe &other );

	template <typename T>
	void displayNums(const T& container);
	//void mergeSortVector( void );
	//void mergeSortDeque( void );

	std::vector<int> getVector( void ) const;
	std::deque<int> getDeque( void ) const;

	static std::vector<int> parseStringWithSpaces( const std::string &str ); 

	/**/

private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	
};

template <typename T>
void PmergeMe::displayNums( const T &container ) {
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " "; 
	}

	std::cout << std::endl;
}

#endif