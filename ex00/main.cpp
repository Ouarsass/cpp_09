/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:54 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/18 04:13:15 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// int main(int argc, char* argv[])
// {
//     if (argc != 2)
//     {
//         std::cerr << "Error: the file .csv is ot exist!" << std::endl;
//         return 1;
//     }
// }

// Fonction utilitaire pour vérifier si la date est valide
bool checkDate(std::string date) {
    // Vérifie si la longueur de la date est de 11 caractères
    if (date.length() != 11) {
        return false;
    }
    // Vérifie si les caractères "-" sont présents aux positions 4 et 7
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    // Vérifie si les caractères restants sont des chiffres
    for (int i = 0; i < 10; i++) {
        // Ignore les caractères "-" aux positions 4 et 7
        if (i == 4 || i == 7) {
            continue;
        }
        if (isdigit(date[i]) == 0) {
            return false;
        }
    }
    // Extrait le jour et le mois de la date
    std::string day = date.substr(8, 2);
    std::string month = date.substr(5, 2);
    // Vérifie si le jour est compris entre 1 et 31 et si le mois est compris entre 1 et 12
    if (std::stoi(day) > 31 || std::stoi(day) < 1) {
        return false;
    }
    if (std::stoi(month) > 12 || std::stoi(month) < 1) {
        return false;
    }
    // Si la date est valide, retourne vrai
    return true;
}

int main(int argc, char **argv) {
    // Vérifie si l'argument d'entrée est valide
    if (argc != 2) {
        std::cerr << "Usage: btc <input_file>" << std::endl;
        return 1;
    }
    
    // Charge les prix du Bitcoin à partir du fichier CSV
    BitcoinExchange exchange("data.csv");

    // Traite le fichier d'entrée et calcule les taux de change
    std::ifstream input(argv[1]);
    if (input.fail()) {
        std::cerr << "Error: Failed to open input file" << std::endl;
        return 1;
    }
    std::string inputLine;
    while (std::getline(input, inputLine)) {
        // Ignore les lignes vides, les commentaires et l'en-tête du fichier
        if (inputLine.empty() || inputLine[0] == '#' || inputLine == "date | value") {
            continue;
        }
        // Extrait la date et la valeur de la ligne d'entrée
        std::string dateStr;
        double value;
        std::istringstream ss(inputLine);
        std::getline(ss, dateStr, '|');
        ss >> value;
        // Vérifie si la ligne d'entrée est valide
        if (ss.fail() || dateStr.empty()) {
            std::cerr << "Error: bad input => " << inputLine << std::endl;
            continue;
        }
        // Vérifie si la date entrée est valide
        if (checkDate(dateStr) == false) {
            std::cerr << "Error: bad date format." << std::endl;
            continue;
        }
        // Vérifie si la valeur de Bitcoin est positive et inférieure à 1000
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		// Calcule le taux de change Bitcoin pour la date donnée, multiplie par la valeur Bitcoin donnée pour obtenir le résultat en USD et affiche le résultat sur la sortie standard
		try
		{
			double exchangeRate = exchange.getExchangeRate(dateStr);
			double result = value * exchangeRate;
			std::cout << dateStr << " => " << value << " = " << result << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
    return 0;
}