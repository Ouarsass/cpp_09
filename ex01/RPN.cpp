/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:06 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/17 20:29:37 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const RPN &obg)
{
	*this = obg;
}
RPN::~RPN(){}
RPN::RPN(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == ' ')
			continue;
		if (str[i] >= '0' && str[i] <= '9')
		{
			int num = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				num = str[i] - '0';	
				i++;
				myStack.push(num);
			}
		}
		else if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && myStack.size() == 2)
		{
			int num2 = myStack.top();
			myStack.pop();
			int num1 = myStack.top();
			myStack.pop();
			if (str[i] == '+')
				myStack.push(num1 + num2);
			else if (str[i] == '-')
				myStack.push(num1 - num2);
			else if (str[i] == '*')
				myStack.push(num1 * num2);
			else if (str[i] == '/')
				myStack.push(num1 / num2);
		}
		else
		{
			std::cout << "Error" << std::endl;
			exit(0);
		}
	}
	if(myStack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		exit(0);
	}
}
RPN & RPN::operator=(const RPN &assign)
{
	this->myStack = assign.myStack;
	return *this;
}
// std::stack<int> RPN::getStack() const
// {
// 	return myStack;
// }
