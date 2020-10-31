/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:59:05 by mli               #+#    #+#             */
/*   Updated: 2020/10/31 21:21:43 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

template <typename T>
void	printSize(std::vector<T> const &vct)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	std::cout << "###############################################" << std::endl;
}

#define tested_type int

int		main(int argc, char **argv)
{
	(void)argc; (void)argv;
	std::vector<tested_type> vct(0, 20);
	std::vector<tested_type>::iterator it;

	it = vct.begin();
	printSize(vct);
	vct.insert(it, 10);
	printSize(vct);
	return (0);
}
