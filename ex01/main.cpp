/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:39:03 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 04:22:33 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int     main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error " << std::endl;
    }
    RPN ReversePolishNotation(argv[1]);
    ReversePolishNotation.print();
    return 0;
}

int main(int argc, char **argv)
{
    // Vérifie le nombre d'argument
    if (argc == 2)
    {
        // Lance une instance et lance la méthode add_data
        RPN rpn;
        rpn.add_data(argv[1]);
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}