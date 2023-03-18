/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:44:33 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 04:21:31 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
private:
	std::stack<int> myStack;
public:
	RPN(const RPN &obg);
	RPN(std::string str);
	~RPN();
	std::stack<int> getStack() const;
	void print()
	{
		std::cout << myStack.top() << std::endl;
    }
	RPN &operator=(const RPN &obg);
};

class RPN
{
    private :
    // Membre privé qui est une pile qui sera utilisée pour stocker les données et les opérandes.
        std::stack<int> stack;

    public :
        RPN();
        ~RPN();
        RPN(RPN const & src);
        RPN &   operator=(RPN const & rhs);
        void    add_data(std::string data);
        int    precedence(char op);
};

#endif