/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:35:47 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/31 11:17:13 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void modify_file(std::string* args) {
	std::string line;
	std::string copied_line;
	std::ifstream inFile(args[0].c_str());

	std::ofstream outFile((args[0] + ".replace").c_str());
	if (!outFile) {
		std::cerr << "Error creating the file!\n";
		delete[] args;
		exit(EXIT_FAILURE);
	}
	
	while (std::getline(inFile, line)) {
		size_t pos = line.find(args[1]);
		if (pos != std::string::npos) {
			copied_line = line.substr(0, pos);
			copied_line += args[2];
			copied_line += line.substr(pos + args[1].size());
			outFile << copied_line << std::endl; 
		}
		else 
			outFile << line << std::endl;
	}

	inFile.close();
	outFile.close();
}