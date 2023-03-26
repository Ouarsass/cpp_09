/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:51 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/26 13:18:06 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange 
{
	private:
		std::map<std::string, double>* btcPrices;
	public:
		BitcoinExchange(const std::string& bitcoinPricesFile);
		BitcoinExchange(const BitcoinExchange& obg);
		~BitcoinExchange();
		double		changeDate(const std::string& date) const;
		BitcoinExchange& operator=(const BitcoinExchange& obg);
};

#endif
