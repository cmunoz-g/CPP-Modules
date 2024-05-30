/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:32:22 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 10:40:06 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of the string variable: " << &str << "\n";
	std::cout << "Memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "Memory address held by stringREF: " << &stringREF << "\n\n";
	
	std::cout << "Value of the string variable: " << str << "\n";
	std::cout << "Value pointed to by stringPTR: " << *(stringPTR) << "\n";
	std::cout << "Value pointed to by stringREF " << stringREF << "\n";
	
	return (0);
}