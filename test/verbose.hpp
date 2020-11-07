/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:48:47 by mli               #+#    #+#             */
/*   Updated: 2020/11/07 17:59:41 by mli              ###   ########.fr       */
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
		Verbose(const bool &do_v = false);
		virtual ~Verbose(void);

		Verbose(const Verbose &src) : \
			index(this->_n++), content(0), do_v(src.do_v) {
			if (this->do_v)
				std::cout << "Verbose::Copy-Constructor called" << std::endl;
			*this = src;
		}

		Verbose	&operator=(const Verbose &rhs) {
			if (this->do_v)
				std::cout << "Verbose::operator=(const Verbose &) called: " \
				<< *this << " = " << rhs << std::endl;
			if (this == &rhs)
				return (*this);
			this->content = rhs.content;
			return (*this);
		}

		Verbose(const int &src, const bool &do_v = false) : \
			index(this->_n++), content(0), do_v(do_v) {
			if (this->do_v)
				std::cout << "Verbose::Int-Constructor called" << std::endl;
			*this = src;
		}

		Verbose	&operator=(const int &rhs) {
			if (this->do_v)
				std::cout << "Verbose::operator=(const int &) called: " \
				<< *this << " = int(" << rhs << ")" << std::endl;
			this->content = rhs;
			return (*this);
		}

		const int	index;
		int			content;
		bool		do_v;

	private:
		static size_t	_n;
};

size_t Verbose::_n = 0;

Verbose::Verbose(const bool &do_v) : index(this->_n++), content(0), do_v(do_v) {
	if (this->do_v)
		std::cout << "Constructor " << *this << std::endl;
}

Verbose::~Verbose(void) {
	if (this->do_v)
		std::cout << "Destructor " << *this << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Verbose const &i) {
	if (i.do_v)
		o << "[" << i.index << "] ";
	o << "(" << i.content << ")";
	return (o);
}

#endif // ********************************************* Verbose_CLASS_HPP end //