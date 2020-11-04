/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:59:05 by mli               #+#    #+#             */
/*   Updated: 2020/11/04 22:23:21 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE std
#endif

#define tested_type int

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = 0)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(int argc, char **argv)
{
	(void)argc; (void)argv;
	TESTED_NAMESPACE::vector<tested_type> vct(5);
	TESTED_NAMESPACE::vector<tested_type>::iterator it;

//	it = vct.begin();
	printSize(vct);
	vct.resize(10);
	printSize(vct, 1);
	return (0);
}
