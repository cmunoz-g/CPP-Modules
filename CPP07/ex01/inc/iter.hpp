/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:16:58 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/04 12:33:57 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename Func>
void iter(T *arr, std::size_t len, Func func) {
	for (std::size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
} 

#endif 