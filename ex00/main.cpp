/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:54 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/20 00:15:00 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Fonction utilitaire pour vérifier si la date est valide
bool validDate(std::string date)
{
    // Vérifie si la longueur de la date est de 11 caractères
    if (date.length() != 11)
        return false;
    // Vérifie si les caractères "-" sont présents aux positions 4 et 7
    if (date[4] != '-' || date[7] != '-')
        return false;
    // Vérifie si les caractères restants sont des chiffres
    for (int i = 0; i < 10; i++)
    {
        // Ignore les caractères "-" aux positions 4 et 7
        if (i == 4 || i == 7)
            continue;
        if (isdigit(date[i]) == 0)
            return false;
    }
    // Extrait le jour et le mois de la date
    std::string day = date.substr(8, 2);
    std::string month = date.substr(5, 2);
    // Vérifie si le jour est compris entre 1 et 31 et si le mois est compris entre 1 et 12
    if (std::stoi(day) > 31 || std::stoi(day) < 1)
        return false;
    if (std::stoi(month) > 12 || std::stoi(month) < 1)
        return false;
    // Si la date est valide, retourne vrai
    return true;
}

int     output(char **argv)
{
    BitcoinExchange exchange("data.csv");
    std::ifstream myfile(argv[1]);
    if (myfile.fail())
    {
        std::cerr << "Error: Failed to open input file" << std::endl;
        return 1;
    }
    std::string inLine;
    while (std::getline(myfile, inLine))
    {
        // Ignore les lignes vides, les commentaires et l'en-tête du fichier
        if (inLine == "date | value" || inLine.empty())
            continue;
        // Extrait la date et la valeur de la ligne d'entrée
        std::string dateStr;
        std::string value;
        std::istringstream ss(inLine);
        std::getline(ss, dateStr, '|');
        ss >> value;
        int i = -1, p = 0;
        while ((value)[++i])
        {
            if ((value)[i] == '.')
                p++;
            if (p > 1)
                {std::cerr << "Error: in value !" << std::endl;break;}
        }
        if (p > 1)continue;
        // Vérifie si la ligne d'entrée est valide
        if (ss.fail() || dateStr.empty()) {
            std::cerr << "Error: bad input --> " << inLine << std::endl;
            continue;
        }
        // Vérifie si la date entrée est valide
        if (validDate(dateStr) == false) {
            std::cerr << "Error: the date is not exist !" << std::endl;
            continue;
        }
        // Vérifie si la valeur de Bitcoin est positive et inférieure à 1000
        if (stof(value) < 0) {
            std::cerr << "Error: is not positive !" << std::endl;
			continue;
		}
		else if (stof(value) > 1000)
		{
			std::cerr << "Error: largest number !" << std::endl;
			continue;
		}
		// Calcule le taux de change Bitcoin pour la date donnée, multiplie par la valeur Bitcoin donnée pour obtenir le résultat en USD et affiche le résultat sur la sortie standard
		try
		{
			double exchangeRate = exchange.changeDate(dateStr);
			double result = stof(value) * exchangeRate;
			std::cout << dateStr << " --> " << value << " = " << result << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
    }
    return(0);
}

int main(int argc, char *argv[])
{
    // Vérifie si l'argument d'entrée est valide
    if (argc != 2)
    {
        std::cerr << "Error: the file is not exist!" << std::endl;
        return (1);
    }
    // Charge les prix du Bitcoin à partir du fichier CSV
    // BitcoinExchange exchange("data.csv");
    output(argv);
    return 0;
}
