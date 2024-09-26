/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:24 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/26 12:50:49 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cerr << "Error: There must be two arguments" << std::endl;
		exit(EXIT_FAILURE);
	}

	RPN rpn;
	rpn.calculate(argv[1]);

	return (0);
}