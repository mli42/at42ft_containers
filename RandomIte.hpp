/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIte.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:25:14 by mli               #+#    #+#             */
/*   Updated: 2021/01/09 22:05:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMITE_CLASS_HPP
# define RANDOMITE_CLASS_HPP

# include "RandomIte_decl.hpp"

namespace ft {

template <typename Spe, bool is_const>
VectIte<Spe, is_const>::VectIte(void) : _value(NULL) {
	return ;
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const>::VectIte(Spe *src) : _value(src) {
	return ;
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const>::VectIte(const VectIte &src) {
	*this = src;
}

/*
template <typename Spe, bool is_const>
VectIte<Spe, is_const>::VectIte(const VectIte<Spe, !is_const> &src) {
	*this = src;
}
*/

template <typename Spe, bool is_const>
VectIte<Spe, is_const>::~VectIte(void) {
	return ;
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const> &VectIte<Spe, is_const>::operator=(const VectIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_value = rhs._value;
	return (*this);
}

template <typename Spe, bool is_const>
bool	VectIte<Spe, is_const>::operator==(const VectIte &rhs) const {
	return (this->_value == rhs._value);
}

template <typename Spe, bool is_const>
bool	VectIte<Spe, is_const>::operator!=(const VectIte &rhs) const {
	return (this->_value != rhs._value);
}

template <typename Spe, bool is_const>
bool	VectIte<Spe, is_const>::operator<(const VectIte &rhs) const {
	return (this->_value < rhs._value);
}

template <typename Spe, bool is_const>
bool	VectIte<Spe, is_const>::operator<=(const VectIte &rhs) const {
	return (this->_value <= rhs._value);
}

template <typename Spe, bool is_const>
bool	VectIte<Spe, is_const>::operator>(const VectIte &rhs) const {
	return (this->_value > rhs._value);
}

template <typename Spe, bool is_const>
bool	VectIte<Spe, is_const>::operator>=(const VectIte &rhs) const {
	return (this->_value >= rhs._value);
}

template <typename Spe, bool is_const>
typename VectIte<Spe, is_const>::reference
	VectIte<Spe, is_const>::operator*(void) const {
	return (*this->_value);
}

template <typename Spe, bool is_const>
typename VectIte<Spe, is_const>::pointer
	VectIte<Spe, is_const>::operator->(void) const {
	return (this->_value);
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const> &VectIte<Spe, is_const>::operator++(void) {
	++this->_value;
	return (*this);
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const> VectIte<Spe, is_const>::operator++(int) {
	VectIte<Spe, is_const>	tmp(*this);
	++this->_value;
	return (tmp);
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const>& VectIte<Spe, is_const>::operator--(void) {
	--this->_value;
	return (*this);
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const> VectIte<Spe, is_const>::operator--(int) {
	VectIte<Spe, is_const>	tmp(*this);
	--this->_value;
	return (tmp);
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const> VectIte<Spe, is_const>::operator+(difference_type n) {
	return (VectIte(this->_value + n));
}

template <typename Spe, bool is_const>
VectIte<Spe, is_const> VectIte<Spe, is_const>::operator-(difference_type n) {
	return (VectIte(this->_value - n));
}

template <typename Spe, bool is_const>
typename VectIte<Spe, is_const>::difference_type
	VectIte<Spe, is_const>::operator-(const VectIte &rhs) {
	return (this->_value - rhs._value);
}

template <typename Spe, bool is_const>
typename VectIte<Spe, is_const>::reference
	VectIte<Spe, is_const>::operator+=(difference_type n) {
	return (*(this->_value += n));
}

template <typename Spe, bool is_const>
typename VectIte<Spe, is_const>::reference
	VectIte<Spe, is_const>::operator-=(difference_type n) {
	return (*this += -n);
}

template <typename Spe, bool is_const>
typename VectIte<Spe, is_const>::reference
	VectIte<Spe, is_const>::operator[](difference_type n) {
	return (this->_value[n]);
}

} // ******************************************************* ft namespace end //

#endif // ******************************************* RANDOMITE_CLASS_HPP end //
