/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:31:13 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/19 17:10:20 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructeur de la classe qui lit les prix à partir d'un fichier CSV
BitcoinExchange::BitcoinExchange(const std::string& bitcoinPricesFile) : btcPrices(new std::map<std::string, double>())
{
    std::ifstream bitcoinFile(bitcoinPricesFile.c_str());
    if (bitcoinFile.fail()) {
        throw std::runtime_error("Error: Failed to open the " + bitcoinPricesFile);
    }
    std::string line;
    std::getline(bitcoinFile, line); // Ignore l'entete du fichier CSV
    while (std::getline(bitcoinFile, line))
    {
        std::istringstream ss(line);
        std::string str;
        double price;
        std::getline(ss, str, '|');
        ss >> price;
        (*btcPrices)[str] = price;
    }
}
// Constructeur de copie qui copie la map
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obg) : btcPrices(new std::map<std::string, double>())
{
    copy(obg);
}

// Destructeur qui libère la mémoire
BitcoinExchange::~BitcoinExchange()
{
    clear();
    delete btcPrices;
}
// Opérateur d'affectation qui copie la map
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obg)
{
    if (this != &obg)
    {
        clear();
        copy(obg);
    }
    return *this;
}
// Méthode qui renvoie le prix à une date donnée
double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = btcPrices->find(date);
    if (it == btcPrices->end())
    {
        // Recherche de la date antérieure la plus proche
        std::map<std::string, double>::const_iterator lower_it = btcPrices->lower_bound(date);
        if (lower_it == btcPrices->begin())
            throw std::runtime_error("Error: the Bitcoin has ben not invalable on this date !");
        else
        {
            --lower_it;
            return lower_it->second;
        }
    }
    else
        return it->second;
}

// Méthode qui copie la map
void BitcoinExchange::copy(const BitcoinExchange& other)
{
    *btcPrices = *other.btcPrices;
}

// Méthode qui vide la map
void BitcoinExchange::clear()
{
    btcPrices->clear();
}