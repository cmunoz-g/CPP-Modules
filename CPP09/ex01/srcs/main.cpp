/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:24 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 12:08:14 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// NOTA: Solo se aceptan expresiones encapsuladas por "", un unico arg. 
// Antes de entregar, razonar si deberia cambiar eso para poder gestionar cada num/operando si vienen cada uno en un arg

int	main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cerr << "Error: There must be two arguments" << std::endl;
		exit(EXIT_FAILURE);
	}

	RPN rpn;
	rpn.calculate(argv[1]);

	return (0);
}