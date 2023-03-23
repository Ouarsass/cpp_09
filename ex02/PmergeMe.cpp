/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:30:43 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/23 01:01:47 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		int nbr = this->check(argv[i]);
		if (nbr == -1)
			return;
		this->dq.push_back(nbr);
		this->vec.push_back(nbr);
	}
	std::cout << "Before : " ;
	this->print(this->dq);
	std::clock_t vectorStart = std::clock();
	this->sort(this->vec);
	std::clock_t vectorEnd = std::clock();
	std::clock_t dequeStart = std::clock();
	this->sort(this->dq);
	std::clock_t dequeEnd = std::clock();
	std::cout << "After  : " ;
	this->print(this->vec);
	double vTiming = (double)(vectorEnd - vectorStart) / 1000;
	double dTiming = (double)(dequeEnd - dequeStart) / 1000;
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector " << vTiming << " us " << std::endl;
	std::cout << "Time to process a range of " << this->dq.size() << " elements with std::deque " << dTiming << " us "  << std::endl;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &obg)
{
	this->dq = obg.dq;
	this->vec = obg.vec;
	return *this;
}
PmergeMe::PmergeMe(const PmergeMe &obg)
{
	*this = obg;
}

PmergeMe::~PmergeMe()
{}

int PmergeMe::check(std::string str)
{
	int i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			std::cerr << "Error" << std::endl;
			return -1;
		}
	}
	std::istringstream ss(str);
	int intiger;
	ss >> intiger;
	if (ss.fail())
		return(-1);
	return (intiger);
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
			if(container[j] > container[j + true])
			{
				int temporair = container[j];
				container[j] = container[j + true];
				container[j + true] = temporair;
			}
		}
	}
}

template <typename T>
void PmergeMe::marge(T &container, T &left, T &right)
{
	int i = 0, j = 0, x = 0;
	while (i < (int)left.size() && j < (int)right.size())
	{
		if (left[i] < right[j])
			container[x++] = left[i++];
		else
			container[x++] = right[j++];
	}
	while (i < (int)left.size())
		container[x++] = left[i++];
	while (j < (int)right.size())
		container[x++] = right[j++];
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
	int mid = size / 2;// 7 / 2 = 3;
	T left(mid);// 3;
	T right(size - mid);// 7 - 3 = 4; 3 + 1;
	for (int i = 0; i < mid; i++)
		left[i] = container[i];
	for (int i = mid; i < size; i++)
		right[i - mid] = container[i];
	sort(left);
	sort(right);
	marge(container, left, right);
}
