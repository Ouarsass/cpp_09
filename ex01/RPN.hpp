/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:44:33 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 13:11:25 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
    private :
    // Membre privé qui est une pile qui sera utilisée pour stocker les données et les opérandes.
        std::stack<int> stack;
    public :
        RPN();
        RPN(RPN const &obg);
        ~RPN();
        RPN &   operator=(RPN const & obg);
        void    add_data(std::string dataBase);
        int     precedence(char op);
};
// class RPN
// {
// private:
// 	std::stack<int> myStack;
// public:
// 	RPN(const RPN &obg);
// 	RPN(std::string str);
// 	~RPN();
// 	std::stack<int> getStack() const;
// 	void print()
// 	{
// 		std::cout << myStack.top() << std::endl;
//     }
// 	RPN &operator=(const RPN &obg);
// };


#endif