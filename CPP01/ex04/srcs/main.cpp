/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:35:21 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/31 11:16:50 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string* transform_into_str(int argc, char *argv[]) {
	std::string* args = new std::string[argc];
	int j = 0;
	
	for (int i = 1; i < argc; i++)
		args[j++] = std::string(argv[i]);
	return (args);
}

int main(int argc, char *argv[])
{
	check_input(argc, argv);
	std::string* args = transform_into_str(argc, argv);
	modify_file(args);
	
	delete[] args;
	return (0);
}