/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustapha <mustapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:30:43 by mouarsas          #+#    #+#             */
/*   Updated: 2023/03/26 06:01:32 by mustapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
	for (int i =1; i < argc; i++)
	{
		int nbr = this->checkIsInt(argv[i]);
		if (nbr == -1)
			return;
		this->dq.push_back(nbr);
		this->vec.push_back(nbr);
	}
	std::cout << "Before : " ;
	for(int i=1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::clock_t vectorStart = std::clock();
	this->sort(this->vec);
	std::clock_t vectorEnd = std::clock();
	std::clock_t dequeStart = std::clock();
	this->sort(this->dq);
	std::clock_t dequeEnd = std::clock();
	std::cout << "After  : " ;
	for(std::vector<int>::iterator it = this->vec.begin() ; it != this->vec.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	double vecTimeInMicrosecondes = (double)(vectorEnd - vectorStart);
	double deqTimeInMicrosecondes = (double)(dequeEnd - dequeStart);
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector " << vecTimeInMicrosecondes << " us " << std::endl;
	std::cout << "Time to process a range of " << this->dq.size() << " elements with std::deque " << deqTimeInMicrosecondes << " us "  << std::endl;
}
int PmergeMe::checkIsInt(std::string str)
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
	int nbr;
	ss >> nbr;
	if (ss.fail())
		return(-1);
	return (nbr);
}
PmergeMe &PmergeMe::operator=(const PmergeMe &obg)
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
template <typename T>
void PmergeMe::insertSorting(T &container)
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
void PmergeMe::sort(T &container)
{
	int size = container.size();
	if (size <= 10)
	{
		insertSorting(container);
		return ;
	}
	int middel = size / 2;// 6 / 2 = 3;
	T L(middel);// 3;
	T R(size - middel);// 6 - 3 = 3;
	for (int i = 0; i < middel; i++)
		L[i] = container[i];
	for (int i = middel; i < size; i++)
		R[i - middel] = container[i];
	sort(L);
	sort(R);
	int i = 0, j = 0, x = 0;
	while (i < (int)L.size() && j < (int)R.size())
	{
		if (L[i] < R[j])
			container[x++] = L[i++];
		else
			container[x++] = R[j++];
	}
	while (i < (int)L.size())
		container[x++] = L[i++];
	while (j < (int)R.size())
		container[x++] = R[j++];
}
