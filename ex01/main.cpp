/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:39:03 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/17 20:28:05 by mouarsas         ###   ########.fr       */
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
