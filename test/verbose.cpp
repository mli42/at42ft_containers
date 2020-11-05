/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:52:48 by mli               #+#    #+#             */
/*   Updated: 2020/11/05 22:18:38 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.hpp"
#include "../vector.hpp"
#include <vector>

#ifndef TESTED_STL
# define TESTED_STL std
#endif

template <typename T>
void	printSize(TESTED_STL::vector<T> const &vct, bool print_content = 0)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	if (print_content)
	{
		typename TESTED_STL::vector<T>::const_iterator it = vct.begin();
		typename TESTED_STL::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	ft_lol(TESTED_STL::vector<T> const &vct)
{
	static int i = 0;
	std::cout << "\nlol [" << i++ << "]\n" << std::endl;
	(void)vct;
}

int		main(void)
{
	TESTED_STL::vector<Verbose> lol(10);
	TESTED_STL::vector<Verbose>::iterator it;
	TESTED_STL::vector<Verbose>::iterator ite;

	printSize(lol);

	it = lol.begin();
	it += 4;
	ite = it + 2;
	std::cout << "begin is " << *it << std::endl;

	lol.erase(it, ite);

	printSize(lol);

	lol.resize(5);

	printSize(lol);

	return (0);
}
