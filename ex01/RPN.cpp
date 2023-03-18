/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:06 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 16:25:58 by mouarsas         ###   ########.fr       */
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
    std::stack<int> stocker; //Création d'une pile (stack) pour stocker les opérandes.
    std::stringstream ss(dataBase); //Utilisation d'un stringstream pour extraire chaque élément de la chaîne de caractères passée en argument.
    std::string token;
    //Boucle while pour parcourir tous les éléments extraits de la chaîne de caractères.
    while (ss >> token)
    {
        // Si le premier caractère de l'élément est un chiffre, on le convertit en entier et on l'ajoute à la pile.
        if (isdigit(token[0]))
            stocker.push(atoi(token.c_str()));
        else if (token.size() > 1 || isdigit(token[0]))
        {
            std::cerr << "Error" << std::endl;
            return;
        }
        // Si l'élément est un opérateur (+, -, *, /), on vérifie qu'il y a au moins 2 opérandes dans la pile.
        // Si ce n'est pas le cas, on affiche une erreur.
        // Sinon, on dépile les 2 dernières opérandes et on applique l'opération correspondante avant de rempiler le résultat.
        else if (token[0] == '*' || token[0] == '/' || token[0] == '+' || token[0] == '-')
        {
            if (stocker.size() < 2)
                {std::cerr << "Error: not enough operands" << std::endl;return;}
            int second = stocker.top();
            stocker.pop();
            int first = stocker.top();
            stocker.pop();
            switch (token[0])
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
        // Si l'élément est une parenthèse ouvrante, on l'ajoute simplement à la pile.
        // else if (token[0] == '(')
        // {
        //     stocker.push('(');
        // }
        // Si l'élément est une parenthèse fermante, on vérifie qu'il y a une parenthèse ouvrante correspondante dans la pile.
        // Si ce n'est pas le cas, on affiche une erreur. Sinon, on dépile la parenthèse ouvrante.
    //     else if (token[0] == ')')
    //     {
    //         if (stocker.empty() || stocker.top() != '(')
    //         {
    //             std::cerr << "Error" << std::endl;
    //             return;
    //         }
    //         stocker.pop();
    //     }
    }
    // Après avoir parcouru tous les éléments, on vérifie qu'il ne reste qu'une seule opérande dans la pile.
    // Si ce n'est pas le cas, on affiche une erreur. Sinon, on affiche le résultat final.
    if (stocker.size() != 1)
    {
        std::cerr << "Error: too many operands" << std::endl;
        return;
    }
    std::cout << stocker.top() << std::endl;
}
