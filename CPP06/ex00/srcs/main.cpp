/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:31:22 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 11:09:53 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cerr << "Wrong number of arguments\n";
	}
	else {
		std::string str(argv[1]);
		ScalarConverter::convert(str);
	}
	return (0);
}