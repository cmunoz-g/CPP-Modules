/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:46 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/16 14:16:54 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Constructor, Destructor*/

PhoneBook::PhoneBook(void) : _index(0) {}
PhoneBook::~PhoneBook(void) {}

/* Member functions */

void	PhoneBook::add(void)
{
	if (_index == 8)
		_index = 0;
	else {
		_contacts[_index].create();
		_index++;
	}
}

void	PhoneBook::search(void)
{
	int	to_display;

	if (!_contacts[0].exists()) {
		std::cout << "\nThere are no contacts yet!\n";
		return ;
	}
	std::cout << RED << "\n" << std::setw(10) << "Index" << RESET << " | "  << RED << std::setw(10) << "First Name" << RESET
		<< " | " << RED << std::setw(10) << "Last Name" << RESET << " | " << RED << std::setw(10) << "Nickname" << RESET << " |\n";
	for (int i = 1; i < 8; i++) {
		if (_contacts[i - 1].exists())
			_contacts[i - 1].list(i - 1);
		else 
			break ;
	}
	std::cout << "\n\nEnter the index of the entry to display...\n";
	std::cin >> to_display;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input! Please enter a valid index.\n";
		search();
	}
	else if (to_display >= 1 && to_display <= 9) {
		if (_contacts[to_display - 1].exists())
			_contacts[to_display - 1].print();
		else {
			std::cout << "\nThere is no contact with that index!\n";
			search();
		}
	}
	else {
		std::cout << "\nThe index is not valid!\n";
		search();
	}
}