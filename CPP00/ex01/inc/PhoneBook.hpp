#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	_contacts[8];
	int		_index;

public:
	PhoneBook(void) : _index(0) {}
	~PhoneBook(void) {}
	void	add(void);
	void	search(void);
};

#endif