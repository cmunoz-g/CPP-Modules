/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:51 by camunozg          #+#    #+#             */
/*   Updated: 2024/10/16 13:36:17 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 

int main(int argc, char *argv[]) {
	if (argc == 1) 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::string str = argv[i];
		for (size_t j = 0; j < str.length(); j++) {
			if (std::islower(str[j]))
				std::cout << static_cast<char>(std::toupper(str[j]));
			else 
				std::cout << static_cast<char>(str[j]);
		}
	}
	std::cout << std::endl;
	return (0);
}