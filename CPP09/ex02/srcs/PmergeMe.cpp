/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:47:23 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 12:15:38 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( int argc, char *argv[]) {

	for (int i = 1; i < argc; i++) {
		std::string str = argv[i];
		if (str.find(' ') != std::string::npos) {
			std::vector<int> parsedNums = parseStringWithSpaces(str);
			_vector.insert(_vector.end(), parsedNums.begin(), parsedNums.end());
			_deque.insert(_deque.end(), parsedNums.begin(), parsedNums.end());
		}
		else {
			std::stringstream ss(str);
			int num;
			if (!(ss >> num)) {
				std::cerr << "Error: Invalid input (wrong character)" << std::endl;
				exit(EXIT_FAILURE);
			}
			else if (num < 0) {
				std::cerr << "Error: Invalid input (negative number)" << std::endl;
				exit(EXIT_FAILURE);
			}
			_vector.push_back(num);
			_deque.push_back(num);
		}
	}
	_unsorted = _vector;
}

PmergeMe::PmergeMe( const PmergeMe &toCopy ) {
	*this = toCopy;
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe &PmergeMe::operator=( const PmergeMe &other ) {
	if (this != &other) {
		_vector = other.getVector();
		_unsorted = _vector;
		_deque = other.getDeque();
	}
	return (*this);
}

/**/

void PmergeMe::calculate(void)
{
	int vectorDuration = mergeSort(_vector);
	int dequeDuration = mergeSort(_deque);
	size_t size = _unsorted.size();
	
	std::cout << "Before: ";
	for (size_t i = 0; i < size; i++) 
		std::cout << _unsorted[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << size << " elements with std::vector : " << vectorDuration << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque : " << dequeDuration << " us" << std::endl;
}

std::vector<int> PmergeMe::getVector(void) const
{
	return (_vector);
}

std::deque<int> PmergeMe::getDeque( void ) const {
	return (_deque);
}

std::vector<int> PmergeMe::parseStringWithSpaces( const std::string &str ) {
	std::vector<int> nums;
	std::istringstream iss(str);
	int num;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isdigit(*it) && !std::isspace(*it)) {
			std::cerr << "Error: Invalid input" << std::endl;
			exit(EXIT_FAILURE);
		}

	while (iss >> num) {
		if (num >= 0)
			nums.push_back(num);
	}
	
	return (nums);
}
