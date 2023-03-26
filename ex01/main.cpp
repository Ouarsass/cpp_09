/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:39:03 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/26 02:08:18 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int     main(int argc, char *argv[])
{
    RPN ReversePolishNotation;
    if (argc != 2)
    {
        std::string sytax = "\"8 9 * 9 - 9 - 9 - 4 - 1 +\"";
        std::cerr << "\033[91mError : please enter somthing like this !.\n"<< sytax << std::endl;
        std::cerr << "And it takes just one argument !." << std::endl;
        return (1);
    }
    ReversePolishNotation.dataBase(argv[1]);
    return (0);
}
