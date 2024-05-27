#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype> 
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits> 

#define RESET	"\x1b[0m"
#define RED 	"\x1b[31m"
#define BOLD	"\033[1m";

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact(void) {}
	~Contact(void) {}
	void	create(void);
	void	print(void);
	void	list(int index);
	bool	exists(void);
};

#endif