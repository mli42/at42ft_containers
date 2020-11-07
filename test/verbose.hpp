/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:48:47 by mli               #+#    #+#             */
/*   Updated: 2020/11/07 13:37:36 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_CLASS_HPP
# define VERBOSE_CLASS_HPP

# include <iostream>
# include <string>

class Verbose;
std::ostream	&operator<<(std::ostream &o, Verbose const &i);

class Verbose {
	public:
		Verbose(void);
		virtual ~Verbose(void);

		Verbose(const Verbose &src) : index(this->_n++), content(0) {
			std::cout << "Verbose::Copy-Constructor called" << std::endl;
			*this = src;
		}

		Verbose	&operator=(const Verbose &rhs) {
			std::cout << "Verbose::operator=(const Verbose &) called: " \
				<< *this << " = " << rhs << std::endl;
			if (this == &rhs)
				return (*this);
			this->content = rhs.content;
			return (*this);
		}

		Verbose(const int &src) : index(this->_n++), content(0) {
			std::cout << "Verbose::Int-Constructor called" << std::endl;
			*this = src;
		}

		Verbose	&operator=(const int &rhs) {
			std::cout << "Verbose::operator=(const int &) called: " \
				<< *this << " = int(" << rhs << ")" << std::endl;
			this->content = rhs;
			return (*this);
		}

		const int	index;
		int			content;

	private:
		static size_t	_n;
};

size_t Verbose::_n = 0;

Verbose::Verbose(void) : index(this->_n++), content(0) {
	std::cout << "Constructor " << *this << std::endl;
}

Verbose::~Verbose(void) {
	std::cout << "Destructor " << *this << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Verbose const &i) {
	o << "[" << i.index << "] (" << i.content << ")";
	return (o);
}

#endif // ********************************************* Verbose_CLASS_HPP end //