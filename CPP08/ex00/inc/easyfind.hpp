/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:38:42 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/09 11:59:37 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(T &cont, int toFind) {
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), toFind);
	if (it == cont.end())
		throw (std::out_of_range("Element not found in the range"));
	return (it);
}

#endif