/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:35:52 by camunozg          #+#    #+#             */
/*   Updated: 2025/02/19 11:36:45 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() 
{
	{
		std::cout << "===== MUTATED STACK TEST 1 =====" << std::endl;
		
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top element: " << mstack.top() << std::endl; // Should be 17
		
		mstack.pop();
		std::cout << "Size after pop: " << mstack.size() << std::endl; // Should be 1

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		// Iterating from begin to end
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "Iterating through MutantStack from begin to end:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << std::endl;
	
	{
		std::cout << "===== MUTATED STACK TEST 2 (Reverse Iterators) =====" << std::endl;
		
		MutantStack<std::string> ms;
		ms.push("Hello");
		ms.push("World");
		ms.push("C++");
		ms.push("Stack");

		std::cout << "Size: " << ms.size() << std::endl;   // Should be 4
		std::cout << "Top element: " << ms.top() << std::endl; // Should be "Stack"
		
		// Reverse iteration
		MutantStack<std::string>::reverse_iterator rit = ms.rbegin();
		MutantStack<std::string>::reverse_iterator rite = ms.rend();

		std::cout << "Iterating from rbegin() to rend():" << std::endl;
		for ( ; rit != rite; ++rit) {
			std::cout << *rit << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "===== MUTATED STACK TEST 3 (Const correctness) =====" << std::endl;
		
		MutantStack<int> msInt;
		msInt.push(1);
		msInt.push(2);
		msInt.push(3);

		const MutantStack<int> constMsInt(msInt);  
		
		// Checking const iterators
		MutantStack<int>::const_iterator cit = constMsInt.begin();
		MutantStack<int>::const_iterator cite = constMsInt.end();
		
		std::cout << "Elements in const MutantStack<int>:" << std::endl;
		for (; cit != cite; ++cit) {
			std::cout << *cit << std::endl;
		}
		
		std::cout << "Size: " << constMsInt.size() << std::endl;
		std::cout << "Top element: " << constMsInt.top() << std::endl; 
		// top() is inherited from std::stack, which provides a const overload
	}

	return 0;
}
