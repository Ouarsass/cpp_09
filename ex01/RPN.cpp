/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:06 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/23 17:59:20 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const &obg)
{*this = obg;}
RPN::~RPN(){}
RPN &RPN::operator=(RPN const &obg)
{
    if (this != &obg)
        this->stocker = obg.stocker;
    return (*this);
}
void RPN::dataBase(std::string dataBase)
{
    for (int i = 0; i < (int)dataBase.length(); i++)
    {
        if (dataBase[i] == ' ')
            continue;
        if (dataBase[i] >= '0' && dataBase[i] <= '9')
        {
            float nbr = dataBase[i] - '0';
            stocker.push(nbr);
        }
        else if (stocker.size() >= 2 && (dataBase[i] == '*' || dataBase[i] == '/' || dataBase[i] == '+' || dataBase[i] == '-'))
        {
            float second = stocker.top();
            // std::cout <<second<<" ---------here\n";
            stocker.pop();
            float first = stocker.top();
            // std::cout <<first<<" ---------here===> \n";
            stocker.pop();
            switch (dataBase[i])
            {
                case '*':
                    stocker.push(first * second);
                    break;
                case '/':
                    stocker.push(first / second);
                    break;
                case '+':
                    stocker.push(first + second);
                    break;
                case '-':
                    stocker.push(first - second);
                    break;
            }
        }
         else
            {std::cerr << "Error" << std::endl;exit(1);}
    }
    if(stocker.size() != 1)
        {std::cerr << "Error: in syntax" << std::endl;exit(1);}
    std::cout << stocker.top() << std::endl;
}
