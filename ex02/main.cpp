/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:29:55 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/22 18:35:00 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if(argc < 2)
        {std::cerr << "Error" << std::endl;return (1);}
    PmergeMe pmergeme(argc, argv);
    return (0);
}
