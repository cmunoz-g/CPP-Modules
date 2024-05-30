/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:39:51 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/29 09:39:52 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 

int	main(int argc, char *argv[]) {

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++)
		{
			if (std::islower(argv[i][j]))
				std::cout << static_cast<char>(argv[i][j] - 32);
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}