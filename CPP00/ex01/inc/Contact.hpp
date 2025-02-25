/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:36 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/16 14:12:15 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Contact(void);
	~Contact(void);
	void	create(void);
	void	print(void);
	void	list(int index);
	bool	exists(void);

	std::string getFirst(void) const;
	std::string getLast(void) const;
	std::string getNick(void) const;
	std::string getNum(void) const;
	std::string getSecret(void) const;
	
	void setFirst(std::string first);
	void setLast(std::string last);
	void setNick(std::string nick);
	void setNum(std::string num);
	void setSecret(std::string secret);
};

#endif