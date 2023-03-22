/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:30:43 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/22 04:23:30 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		int num = this->check(av[i]);
		if (num == -1)
			return ;
		this->_deque.push_back(num);
		this->_vector.push_back(num);
	}
	std::cout << "Before : " ;
	this->print(this->_deque);
	std::clock_t vstart = std::clock();
	this->sort(this->_vector);
	std::clock_t vend = std::clock();
	std::clock_t dstart = std::clock();
	this->sort(this->_deque);
	std::clock_t dend = std::clock();
	std::cout << "After : " ;
	this->print(this->_vector);
	
	double vduration = (double)(vend - vstart) / 1000;
	double dduration = (double)(dend - dstart) / 1000;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector " << vduration << " us " << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque " << dduration << " us "  << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy){*this = copy;}

PmergeMe::~PmergeMe(){}

PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	this->_deque = assign._deque;
	this->_vector = assign._vector;
	return *this;
}


int PmergeMe::check(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			std::cout << "Error" << std::endl;
			return -1;
		}
		i++;
	}
	try
	{
		return std::stoi(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
	}
	return -1;
}

template <typename T>
void PmergeMe::print(T &container)
{
	if(container.size() <= 5)
	{
		for (typename T::iterator it = container.begin(); it != container.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		typename T::iterator it = container.begin();
		for (int i = 0; i < 5; i++)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << "[...]" << std::endl;
	}
}

template <typename T>
void PmergeMe::insert_sort(T &container)
{
	for(int i = 0; i < (int)container.size(); i++)
	{
		for(int j = 0; j < (int)container.size() - 1; j++)
		{
			if(container[j] > container[j + 1])
			{
				int temp = container[j];
				container[j] = container[j + 1];
				container[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void PmergeMe::marge(T &container, T &left, T &right)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < (int)left.size() && j < (int)right.size())
	{
		if (left[i] < right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while (i < (int)left.size())
		container[k++] = left[i++];
	while (j < (int)right.size())
		container[k++] = right[j++];
}

template <typename T>
void PmergeMe::sort(T &container)
{
	int size = container.size();
	if (size <= 10)
	{
		insert_sort(container);
		return ;
	}
	int mid = size / 2;
	T left(mid);
	T right(size - mid);
	for (int i = 0; i < mid; i++)
		left[i] = container[i];
	for (int i = mid; i < size; i++)
		right[i - mid] = container[i];
	sort(left);
	sort(right);
	marge(container, left, right);
}
