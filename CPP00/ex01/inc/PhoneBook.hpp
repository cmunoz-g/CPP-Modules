/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:39 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/29 09:39:40 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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