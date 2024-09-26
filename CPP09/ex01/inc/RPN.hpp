/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:20 by camunozg          #+#    #+#             */
/*   Updated: 2024/09/26 12:50:31 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stack>

class RPN {

public:
	RPN(); 
	RPN( const RPN &toCopy );
	~RPN();
	
	RPN &operator=( const RPN &other );

	void calculate(const std::string line);
	static bool isOp(char c);
	static double performOp(double a, double b, char operand);

private:
	std::stack<double> _numbers;
};

#endif
