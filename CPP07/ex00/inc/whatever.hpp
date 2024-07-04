/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:07:55 by camunozg          #+#    #+#             */
/*   Updated: 2024/07/04 12:15:50 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// Function templates allow you to write generic functions that can work with any data type.
// They are defined by using the 'template' keyword followed by a template parameter list.

template <typename S>
void swap(S &a, S &b) {
	S temp = a;
	a = b;
	b = temp;
}

template <typename m> 
const m min(const m &a, const m &b) {
	return (a <= b ? a : b);
}

template <typename M>
const M max(const M &a, const M &b) {
	return (a >= b ? a : b);
}

#endif