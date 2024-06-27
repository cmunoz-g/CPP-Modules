/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:31:22 by camunozg          #+#    #+#             */
/*   Updated: 2024/06/27 11:11:15 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Checkear si debo gestionar el pseudoliteral nanf. En el subject no viene pero comprobar en la hoja de correcion
// Checkear si los resultados de los pseudoliterales son los esperados

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