/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:41 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/16 14:12:48 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* Constructor, Destructor */

Contact::Contact(void) {}
Contact::~Contact(void) {}

/* Member functions */

void	Contact::create( void )
{
	std::string phone;
	bool		only_digits;

	std::cout << "\nEntering information for a new contact!\n\n";
	std::cout << "Enter their first name...\n";
	std::cin >> _firstName;
	std::cout << "Enter their last name...\n";
	std::cin >> _lastName;
	std::cout << "Enter their nickname...\n";
	std::cin >> _nickName;
	while (1)
	{
		only_digits = true;
		std::cout << "Enter their phone number...\n";
		std::cin >> phone;
		for (int i = 0; phone[i]; i++)
			if (!std::isdigit(phone[i])) {
				std::cout << "\nOnly numbers are allowed!\n\n";
				only_digits = false;
				break ;
			}	
		if (only_digits == true) {
			_phoneNumber = phone;
			break ;
		}
	}
	std::cout << "Finally, what is their darkest secret?\n";
	std::cin >> _darkestSecret;
	std::cout << "\n";
}

void	Contact::list( int index )
{
	std::cout << std::setw(10) << index + 1 << " | ";
	if (_firstName.length() > 10)
		std::cout << _firstName.substr(0, 9) << ". | ";
	else
		std::cout << std::setw(10) << _firstName << " | ";
	if (_lastName.length() > 10)
		std::cout << _lastName.substr(0, 9) << ". | ";
	else
		std::cout << std::setw(10) << _lastName << " | ";
	if (_nickName.length() > 10)
		std::cout << _nickName.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << _nickName << " |";
	std::cout << "\n";
}

bool	Contact::exists( void )
{
	return (!(_firstName.empty()));
}

void	Contact::print( void )
{
	std::cout << "\nFirst name    : " << _firstName << "\n";
	std::cout << "Last name     : " << _lastName << "\n";
	std::cout << "Nickname      : " << _nickName << "\n";
	std::cout << "Phone number  : " << _phoneNumber << "\n";
	std::cout << "Darkest secret: " << _darkestSecret << "\n\n";

}

/* Getters && Setters */

std::string Contact::getFirst( void ) const {
	return (this->_firstName);
}

std::string Contact::getLast( void ) const {
	return (this->_lastName);
}

std::string Contact::getNick( void ) const {
	return (this->_nickName);
}

std::string Contact::getNum( void ) const {
	return (this->_phoneNumber);
}

std::string Contact::getSecret( void ) const {
	return (this->_darkestSecret);
}

void Contact::setFirst( std::string first ) {
	this->_firstName = first;
}

void Contact::setLast( std::string last ) {
	this->_lastName = last;
} 

void Contact::setNick( std::string nick ) {
	this->_nickName = nick;
}

void Contact::setNum( std::string num ) {
	this->_phoneNumber = num;
}

void Contact::setSecret( std::string secret ) {
	this->_darkestSecret = secret;
}