/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:47:26 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 12:09:03 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	for (int i = 1; i < 6; i++)
		v.push_back(i);
	
	std::set<int> s;
	for (int i = 1; i < 4; i++)
		s.insert(i);
	
	try {
		std::vector<int>::const_iterator it_v = ::easyfind(v, 4);
		std::cout << "The element " << *it_v << " is in the vector" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		std::vector<int>::const_iterator it_v = ::easyfind(v, 10);
		std::cout << "The element " << *it_v << " is in the vector" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::set<int>::const_iterator it_s = ::easyfind(s, 1);
		std::cout << "The element " << *it_s << " is in the set" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		std::set<int>::const_iterator it_s = ::easyfind(s, 10);
		std::cout << "The element " << *it_s << " is in the set" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	
	return (0);
}