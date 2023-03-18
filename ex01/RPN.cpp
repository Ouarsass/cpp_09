/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:06 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 04:20:29 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


// Constructeur par défaut de la classe RPN.
RPN::RPN()
{
}

// Destructeur de la classe RPN
RPN::~RPN()
{
}

// Constructeur de copie 
RPN::RPN(RPN const & src)
{
    *this = src;
}


// Opérateur d'assignation qui effectue une copie de l'objet source sur l'objet courant
RPN & RPN::operator=(RPN const & rhs)
{
    if (this != &rhs) {
        this->stack = rhs.stack;
    }
    return *this;
}

void RPN::add_data(std::string data)
{
    std::stack<int> stack; //Création d'une pile (stack) pour stocker les opérandes.
    std::stringstream ss(data); //Utilisation d'un stringstream pour extraire chaque élément de la chaîne de caractères passée en argument.
    std::string token;
    //Boucle while pour parcourir tous les éléments extraits de la chaîne de caractères.
    while (ss >> token)
    {
        // Si le premier caractère de l'élément est un chiffre, on le convertit en entier et on l'ajoute à la pile.
        if (isdigit(token[0]))
            stack.push(atoi(token.c_str()));
        else if (token.size() > 1 || isdigit(token[0]))
        {
            std::cout << "Error" << std::endl;
            return;
        }
        // Si l'élément est un opérateur (+, -, *, /), on vérifie qu'il y a au moins 2 opérandes dans la pile.
        // Si ce n'est pas le cas, on affiche une erreur.
        // Sinon, on dépile les 2 dernières opérandes et on applique l'opération correspondante avant de rempiler le résultat.
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error: not enough operands" << std::endl;
                return;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            switch (token[0])
            {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
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
                std::cout << "Error" << std::endl;
                return;
            }
            stack.pop();
        }
    }
    // Après avoir parcouru tous les éléments, on vérifie qu'il ne reste qu'une seule opérande dans la pile.
    // Si ce n'est pas le cas, on affiche une erreur. Sinon, on affiche le résultat final.
    if (stack.size() != 1)
    {
        std::cout << "Error: too many operands" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}