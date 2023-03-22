/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:54 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/22 22:28:59 by mouarsas         ###   ########.fr       */
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
    int daily, monthly;
    sday >> daily;
    smonth >> monthly;
    if (daily > 31 || daily < 1)
        return false;
    if (monthly > 12 || monthly < 1)
        return false;
    return true;
}

int checkValue(std::string value)
{
    for(int e = 0; value[e];e++)
    {
        if (value[e] == '.' && (!isdigit(value[e-1]) || !isdigit(value[e+1])))
        {
            std::cerr << "Error: bad value" << std::endl;
            return 0;
        }
        else if (!isdigit(value[e]) && value[e] != '.')
        {
            std::cerr << "Error: bad value" << std::endl;
            return 0;
        }
    }
    return 1;
}

int     output(char **argv)
{
    bool first = true;
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
        if ((first && (inLine == "date | value")) || inLine.empty())
        {
            first = false;   
            continue;
        }
        std::string dateStr;
        std::string value;
        std::istringstream ss(inLine);
        //// count pipes and hiphens '-'
        std::getline(ss, dateStr, '|');
        ss >> value;
        if (!checkValue(value))
            continue;
            
        int i = -1, p = 0;
        while ((value)[++i])
        {
            if ((value)[i] == '.')
                p++;
            if (p > 1)
                {std::cerr << "Error: bad value !" << std::endl;break;}
        }
        if (p > 1)continue;
        if (ss.fail() || dateStr.empty()){
            std::cerr << "Error: bad input --> " << inLine << std::endl;
            continue;
        }
        if (validDate(dateStr) == false){
            std::cerr << "Error: the date is not exist !" << std::endl;
            continue;
        }
        if (atof(value.c_str()) < 0){
            std::cerr << "Error: is not positive !" << std::endl;
			continue;
		}
		else if (atof(value.c_str()) > 1000)
		{
			std::cerr << "Error: largest number !" << std::endl;
			continue;
		}
		// Calcule le taux de change Bitcoin pour la date donnée, multiplie par la valeur Bitcoin donnée pour obtenir le résultat en USD et affiche le résultat sur la sortie standard
        first = false;
		try
		{
			double exchangeRate = exchange.changeDate(dateStr);
			double result = atof(value.c_str()) * exchangeRate;
			std::cout << dateStr << " --> " << value << " = " << result << std::endl;
		}catch (std::exception& e){
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
        std::cerr << "\033[91mError: the file is not exist!" << std::endl;
        return (1);
    }
    // Charge les prix du Bitcoin à partir du fichier CSV
    // BitcoinExchange exchange("data.csv");
    output(argv);
    return 0;
}
