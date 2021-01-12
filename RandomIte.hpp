/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIte.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:25:14 by mli               #+#    #+#             */
/*   Updated: 2021/01/12 13:38:06 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMITE_CLASS_HPP
# define RANDOMITE_CLASS_HPP

# include "RandomIte_decl.hpp"

namespace ft {

template <typename Spe>
RandIte<Spe>::RandIte(void) : _value(NULL) {
	return ;
}

template <typename Spe>
RandIte<Spe>::RandIte(Spe *src) : _value(src) {
	return ;
}

template <typename Spe>
RandIte<Spe>::RandIte(const RandIte &src) {
	*this = src;
}

template <typename Spe>
RandIte<Spe>::~RandIte(void) {
	return ;
}

template <typename Spe>
RandIte<Spe> &RandIte<Spe>::operator=(const RandIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_value = rhs._value;
	return (*this);
}

template <typename Spe>
bool	RandIte<Spe>::operator==(const RandIte &rhs) const {
	return (this->_value == rhs._value);
}

template <typename Spe>
bool	RandIte<Spe>::operator!=(const RandIte &rhs) const {
	return (this->_value != rhs._value);
}

template <typename Spe>
bool	RandIte<Spe>::operator<(const RandIte &rhs) const {
	return (this->_value < rhs._value);
}

template <typename Spe>
bool	RandIte<Spe>::operator<=(const RandIte &rhs) const {
	return (this->_value <= rhs._value);
}

template <typename Spe>
bool	RandIte<Spe>::operator>(const RandIte &rhs) const {
	return (this->_value > rhs._value);
}

template <typename Spe>
bool	RandIte<Spe>::operator>=(const RandIte &rhs) const {
	return (this->_value >= rhs._value);
}

template <typename Spe>
RandIte<Spe> &RandIte<Spe>::operator++(void) {
	++this->_value;
	return (*this);
}

template <typename Spe>
RandIte<Spe> RandIte<Spe>::operator++(int) {
	RandIte<Spe>	tmp(*this);
	++this->_value;
	return (tmp);
}

template <typename Spe>
RandIte<Spe>& RandIte<Spe>::operator--(void) {
	--this->_value;
	return (*this);
}

template <typename Spe>
RandIte<Spe> RandIte<Spe>::operator--(int) {
	RandIte<Spe>	tmp(*this);
	--this->_value;
	return (tmp);
}

template <typename Spe>
typename RandIte<Spe>::difference_type
	RandIte<Spe>::operator-(const RandIte &rhs) const {
	return (this->_value - rhs._value);
}

template <typename Spe>
RandIte<Spe> RandIte<Spe>::operator+(difference_type n) const {
	return (RandIte(this->_value + n));
}

template <typename Spe>
RandIte<Spe> RandIte<Spe>::operator-(difference_type n) const {
	return (RandIte(this->_value - n));
}

/*
template <typename Spe>
typename RandIte<Spe>::reference
	RandIte<Spe>::operator*(void) const {
	return (*this->_value);
}

template <typename Spe>
typename RandIte<Spe>::pointer
	RandIte<Spe>::operator->(void) const {
	return (this->_value);
}

template <typename Spe>
typename RandIte<Spe>::reference
	RandIte<Spe>::operator+=(difference_type n) {
	return (*(this->_value += n));
}

template <typename Spe>
typename RandIte<Spe>::reference
	RandIte<Spe>::operator-=(difference_type n) {
	return (*this += -n);
}

template <typename Spe>
typename RandIte<Spe>::reference
	RandIte<Spe>::operator[](difference_type n) {
	return (this->_value[n]);
}
*/

} // ******************************************************* ft namespace end //

#endif // ******************************************* RANDOMITE_CLASS_HPP end //
