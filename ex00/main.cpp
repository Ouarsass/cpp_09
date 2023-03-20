/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:54 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/20 20:02:58 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool validDate(std::string date)
{
    if (date.length() != 11)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (isdigit(date[i]) == 0)
            return false;
    }
    std::string day = date.substr(8, 2);
    std::string month = date.substr(5, 2);
    std::istringstream sday(day), smonth(month);
    int nDay, nmount;
    sday >> nDay;
    smonth >> nmount;
    if (nDay > 31 || nDay < 1)
        return false;
    if (nmount > 12 || nmount < 1)
        return false;
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
        if (inLine == "date | value" || inLine.empty())
            continue;
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
        if (ss.fail() || dateStr.empty()) {
            std::cerr << "Error: bad input --> " << inLine << std::endl;
            continue;
        }
        if (validDate(dateStr) == false) {
            std::cerr << "Error: the date is not exist !" << std::endl;
            continue;
        }
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
