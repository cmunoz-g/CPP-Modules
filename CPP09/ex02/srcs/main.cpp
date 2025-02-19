/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:51:20 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 12:17:20 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int argc, char *argv[] ) {
		
	if (argc < 2) {
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
		
	PmergeMe merger(argc, argv);
	merger.calculate();
	return (0);
	
}