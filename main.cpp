/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:59:05 by mli               #+#    #+#             */
/*   Updated: 2020/10/31 16:41:33 by mli              ###   ########.fr       */
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
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "###############################################" << std::endl;
}

#define tested_type double

int		main(int argc, char **argv)
{
	(void)argc; (void)argv;
	std::vector<tested_type> vct;
	ft::vector<tested_type> ft_vct;

	printSize(vct);
	std::cout << ft_vct.max_size() << std::endl
			  << vct.max_size() << std::endl;
	std::cout << (ft_vct.max_size() == vct.max_size()) << std::endl;
	return (0);
}
