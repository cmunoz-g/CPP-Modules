/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:41:36 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 10:38:33 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() { 
	Bureaucrat jane("Jane", 100);
	Form invoice("Invoice", 100, 100);
	Form purchase("Purchase", 20, 30);
	Form accounts("Accounts", 120, 140);

	std::cout << std::endl;

	try {										
		Form invalid("invalid", 200, 10);				// Trying to initialize an invalid Form
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	invoice.beSigned(jane);								// Form gets signed
	jane.signForm(accounts);							// Bureaucrat signs form
	jane.signForm(invoice);								// Trying to sign a previously signed form does nothing
	
	jane.signForm(purchase);							// Trying to sign a form without a high enough grade (try/catch statement inside the method)

	std::cout << purchase << std::endl;					// << operator overload
	
	return (0);
}