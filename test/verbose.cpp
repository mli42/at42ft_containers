/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:52:48 by mli               #+#    #+#             */
/*   Updated: 2020/11/05 20:11:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "verbose.hpp"

template <typename T>
void	printSize(std::vector<T> const &vct, bool print_content = 0)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	if (print_content)
	{
		typename std::vector<T>::const_iterator it = vct.begin();
		typename std::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	ft_lol(std::vector<T> const &vct)
{
	static int i = 0;
	std::cout << "\nlol [" << i++ << "]\n" << std::endl;
	(void)vct;
}

int		main(void)
{
	std::vector<Verbose> lol(3);
	std::vector<Verbose>::iterator it;

	printSize(lol);

	it = lol.begin();
	std::cout << "begin is " << *it << std::endl;

	lol.erase(it);

	printSize(lol);

	lol.resize(5);

	printSize(lol);

	return (0);
}
