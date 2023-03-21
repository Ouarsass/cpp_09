/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:06 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/21 01:01:54 by mouarsas         ###   ########.fr       */
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
    // std::stack<int> stocker; //Création d'une pile (stack) pour stocker les opérandes.
    // std::stringstream sstream(dataBase); //Utilisation d'un stringstream pour extraire chaque élément de la chaîne de caractères passée en argument.
    // std::string token;
    // //Boucle while pour parcourir tous les éléments extraits de la chaîne de caractères.
    // while (sstream >> token)
    // {
    //     // std::cout <<token[1]<<" ************\n";
    //     // Si le premier caractère de l'élément est un chiffre, on le convertit en entier et on l'ajoute à la pile.
    //     if (isdigit(token[0]))
    //         stocker.push(atoi(token.c_str()));
    //     else if (token.size() > 1 || isdigit(token[0]))
    //     {
    //         std::cerr << "Error" << std::endl;
    //         return;
    //     }
    //     // Si l'élément est un opérateur (+, -, *, /), on vérifie qu'il y a au moins 2 opérandes dans la pile.
    //     // Si ce n'est pas le cas, on affiche une erreur.
    //     // Sinon, on dépile les 2 dernières opérandes et on applique l'opération correspondante avant de rempiler le résultat.

    for (int i = 0; i < (int)dataBase.length(); i++)
    {
        if (dataBase[i] == ' ')
            continue;
        if (dataBase[i] >= '0' && dataBase[i] <= '9')
        {
            int nbr = dataBase[i] - '0';
            stocker.push(nbr);
        }
        else if ((dataBase[i] == '*' || dataBase[i] == '/' || dataBase[i] == '+' || dataBase[i] == '-') && stocker.size() >= 2)
        {
            int second = stocker.top();
            // std::cout <<second<<" ---------here\n";
            
            stocker.pop();
            int first = stocker.top();
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
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    
    }
    if(stocker.size() != 1)
    {
        std::cout << "Error1" << std::endl;
        exit(1);
    }
    std::cout << stocker.top() << std::endl;
}
    // Après avoir parcouru tous les éléments, on vérifie qu'il ne reste qu'une seule opérande dans la pile.
    // Si ce n'est pas le cas, on affiche une erreur. Sinon, on affiche le résultat final.
//     if (stocker.size() != 1)
//         {std::cerr << "Error: in syntax" << std::endl;return;}
//     std::cout << stocker.top() << std::endl;
// }
