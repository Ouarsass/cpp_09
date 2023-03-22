/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:31:02 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/22 04:25:57 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <chrono>/////////
class PmergeMe
{
	private:
		std::deque<int> _deque;////// the deque container
		std::vector<int> _vector;
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &assign);
		
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
