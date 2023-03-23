/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:31:02 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/23 00:55:35 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <chrono>
#include<sstream>

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
		int check(std::string str);
		template <typename T>
		void print(T &container);
		template <typename T>
		void sort(T &container);
		template <typename T>
		void marge(T &container, T &left, T &right);
		template <typename T>
		void insert_sort(T &container);
		
};

#endif
