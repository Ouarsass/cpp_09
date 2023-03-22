/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:44:33 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/22 22:36:43 by mouarsas         ###   ########.fr       */
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
        std::stack<float> stocker;
    public:
        RPN();
        RPN(RPN const &obg);
        ~RPN();
        void    dataBase(std::string dataBase);
        RPN     &operator=(RPN const &obg);
};

#endif