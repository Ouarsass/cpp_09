/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:31:02 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/23 16:01:15 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <chrono>
#include <sstream>

class PmergeMe
{
	private:
		std::deque<int> dq;
		std::vector<int> vec;
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &obg);
		PmergeMe &operator=(const PmergeMe &obg);
		template <typename T>
		void printingNbr(T &container);
		template <typename T>
		void sort(T &container);
		template <typename T>
		void insertSorting(T &container);
		int checkIsInt(std::string str);
		
};

#endif
