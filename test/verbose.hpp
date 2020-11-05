/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:48:47 by mli               #+#    #+#             */
/*   Updated: 2020/11/05 20:20:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_CLASS_HPP
# define VERBOSE_CLASS_HPP

# include <iostream>
# include <string>

class Verbose;
std::ostream	&operator<<(std::ostream &o, Verbose const & i);

class Verbose {
	public:
		Verbose(void);
		virtual ~Verbose(void);

		Verbose(const Verbose &src) : index(this->_n++) {
			std::cout << "Verbose::Copy-Constructor called" << std::endl;
			*this = src;
		}

		Verbose	&operator=(const Verbose &rhs) {
			std::cout << "Verbose::operator=() called: " << *this \
				<< " = " << rhs << std::endl;
			if (this == &rhs)
				return (*this);
			this->index = rhs.index;
			return (*this);
		}

		int	index;

	private:
		static size_t	_n;
};

size_t Verbose::_n = 0;

Verbose::Verbose(void) : index(this->_n++) {
	std::cout << "Constructor [" << this->index << "]" << std::endl;
}

Verbose::~Verbose(void) {
	std::cout << "Destructor [" << this->index << "]" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Verbose const &i) {
	o << "[" << i.index << "]";
	return (o);
}

#endif // ************************************************ Verbose_CLASS_HPP end //