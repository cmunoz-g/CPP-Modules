/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:50:58 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/30 10:15:39 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde ( int N, std::string name) {
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].zombieName(name);
	return (horde);
}