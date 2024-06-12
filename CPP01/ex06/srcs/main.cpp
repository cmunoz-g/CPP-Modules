/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:05:09 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/12 10:36:16 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl complainer;
	
	if (argc == 2)
		complainer.complain(std::string(argv[1]));
	else
		std::cout << "There must be 2 arguments!\n";
	return (0);
}