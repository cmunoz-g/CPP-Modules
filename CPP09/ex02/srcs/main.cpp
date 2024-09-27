/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:51:20 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/27 09:54:51 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int argc, char *argv[] ) {
	
	PmergeMe merger(argc, argv);
	
	merger.displayNums(merger.getDeque());
	std::cout << "----------------" << std::endl;
	merger.displayNums(merger.getVector());

	return (0);
}