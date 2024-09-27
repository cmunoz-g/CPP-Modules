/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:36:45 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/27 11:52:01 by camunozg         ###   ########.fr       */
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
	int mergeSort( T& container );
	void calculate( void );
	
	std::vector<int> getVector( void ) const;
	std::deque<int> getDeque( void ) const;

	static std::vector<int> parseStringWithSpaces( const std::string &str ); 

	/**/

private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::vector<int> _unsorted;
	
};

/**/

// Sorts pairs and separates them into two different containers.
// If there is an odd number of elements, send the last one to remaining.
// For each element in remaining, find where to insert with lower (lower_bound() uses binary search) and do so.

template <typename T>
int PmergeMe::mergeSort( T& container ) {

	typedef typename T::iterator Titer;
	T sorted;
	T remaining;

	std::clock_t start = std::clock();
	
	for (size_t i = 0; i < container.size() - 1; i += 2) { 						
		if (container[i] < container[i + 1]) {
			sorted.push_back(container[i]);
			remaining.push_back(container[i + 1]);
		}
		else {
			sorted.push_back(container[i + 1]);
			remaining.push_back(container[i]);
		}
	}

	if (container.size() % 2 != 0)												
		remaining.push_back(container.back());
	
	std::sort(sorted.begin(), sorted.end());

	for (Titer it = remaining.begin(); it != remaining.end(); ++it) {			
		Titer lower = std::lower_bound(sorted.begin(), sorted.end(), (*it));
		sorted.insert(lower, (*it));
	}
	
	std::clock_t end = std::clock();
	long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;

	std::copy(sorted.begin(), sorted.end(), container.begin());
	
	return (duration);
}

#endif