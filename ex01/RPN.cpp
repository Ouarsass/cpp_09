/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:06 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 13:20:57 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}
 
RPN::RPN(RPN const &obg)
{
    *this = obg;
}

RPN &RPN::operator=(RPN const &obg)
{
    if (this != &obg)
        this->stack = obg.stack;
    return (*this);
}

void RPN::add_data(std::string dataBase)
{
    std::stack<int> stack; //Création d'une pile (stack) pour stocker les opérandes.
    std::stringstream ss(dataBase); //Utilisation d'un stringstream pour extraire chaque élément de la chaîne de caractères passée en argument.
    std::string token;
    //Boucle while pour parcourir tous les éléments extraits de la chaîne de caractères.
    while (ss >> token)
    {
        // Si le premier caractère de l'élément est un chiffre, on le convertit en entier et on l'ajoute à la pile.
        if (isdigit(token[0]))
            stack.push(atoi(token.c_str()));
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
            if (stack.size() < 2)
                {std::cerr << "Error: not enough operands" << std::endl;return;}
            int second = stack.top();
            stack.pop();
            int first = stack.top();
            stack.pop();
            switch (token[0])
            {
                case '+':
                    stack.push(first + second);
                    break;
                case '-':
                    stack.push(first - second);
                    break;
                case '*':
                    stack.push(first * second);
                    break;
                case '/':
                    stack.push(first / second);
                    break;
            }
        }
        // Si l'élément est une parenthèse ouvrante, on l'ajoute simplement à la pile.
        else if (token[0] == '(')
        {
            stack.push('(');
        }
        // Si l'élément est une parenthèse fermante, on vérifie qu'il y a une parenthèse ouvrante correspondante dans la pile.
        // Si ce n'est pas le cas, on affiche une erreur. Sinon, on dépile la parenthèse ouvrante.
        else if (token[0] == ')')
        {
            if (stack.empty() || stack.top() != '(')
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            stack.pop();
        }
    }
    // Après avoir parcouru tous les éléments, on vérifie qu'il ne reste qu'une seule opérande dans la pile.
    // Si ce n'est pas le cas, on affiche une erreur. Sinon, on affiche le résultat final.
    if (stack.size() != 1)
    {
        std::cerr << "Error: too many operands" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}
