/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:06:50 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/31 10:49:48 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

bool file_exists(char* filename) {
	std::fstream file(filename, std::ios::in | std::ios::out);
	bool exists = file.good();
	file.close();
	return (exists);
}

void check_input(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments\n";
		exit(EXIT_FAILURE);
	}
	else if (!file_exists(argv[1])) {
		std::cerr << "The file does not exist!\n";
		exit(EXIT_FAILURE);
	}
}