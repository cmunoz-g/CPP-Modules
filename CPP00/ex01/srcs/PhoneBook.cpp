#include "PhoneBook.hpp"

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