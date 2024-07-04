/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:27:12 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/04 12:54:40 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(const T &element) {
	std::cout << element << std::endl;
}

int main() {
	int i[] = {0, 1, 2};
	std::string s[] = {"Hello", "World"};

	::iter(i, 3, printElement);
	::iter(s, 2, printElement);

	return (0);
}