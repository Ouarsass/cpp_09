/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:31:13 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/26 01:52:30 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& bitcoinPricesFile) : btcPrices(new std::map<std::string, double>())
{
    std::string line;
    std::ifstream bitcoinFile(bitcoinPricesFile.c_str());
    if (bitcoinFile.fail())
        {std::cerr << "Error: Failed to open the file "<< bitcoinPricesFile << std::endl;exit(1);}
    std::getline(bitcoinFile, line);
    while (std::getline(bitcoinFile, line))
    {
        std::istringstream ss(line);
        double price;
        std::string str;
        std::getline(ss, str, ',');
        ss >> price;
        (*btcPrices)[str] = price;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obg) : btcPrices(new std::map<std::string, double>())
{
    *btcPrices = *obg.btcPrices;
}
BitcoinExchange::~BitcoinExchange()
{
    btcPrices->clear();
    delete btcPrices;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obg)
{
    if (this != &obg)
    {
        btcPrices->clear();
        *btcPrices = *obg.btcPrices;
    }
    return *this;
}
double BitcoinExchange::changeDate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator itr = btcPrices->find(date);
    if (itr == btcPrices->end())
    {
        std::map<std::string, double>::const_iterator ptr = btcPrices->lower_bound(date);
        if (ptr == btcPrices->begin())
            throw std::runtime_error("Error: the Bitcoin has ben not invalable on this date !");
        else
        {
            --ptr;
            return ptr->second;
        }
    }
    else
        return itr->second;
}
