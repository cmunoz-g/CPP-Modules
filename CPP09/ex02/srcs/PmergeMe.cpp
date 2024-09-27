/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:47:23 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/27 10:27:30 by camunozg         ###   ########.fr       */
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
				std::cerr << "Invalid input" << std::endl;
				exit(EXIT_FAILURE);
			}
			_vector.push_back(num);
			_deque.push_back(num);
		}
	}

}

PmergeMe::PmergeMe( const PmergeMe &toCopy ) {
	*this = toCopy;
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe &PmergeMe::operator=( const PmergeMe &other ) {
	if (this != &other) {
		_vector = other.getVector();
		_deque = other.getDeque();
	}
	return (*this);
}

/**/

std::vector<int> PmergeMe::getVector( void ) const {
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

	while (iss >> num)
		nums.push_back(num);
	
	return (nums);
}

// public:

// 	template <typename T>
// 	void displayNums(const T& container);
// 	void mergeSortVector( void );
// 	void mergeSortDeque( void );

// 	std::vector<int> getVector( void );
// 	std::deque<int> getDeque( void );

// 	/**/

// private:
// 	std::vector<int> _vector;
// 	std::deque<int> _deque;
	