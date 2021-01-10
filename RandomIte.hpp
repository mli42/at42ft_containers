/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIte.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:25:14 by mli               #+#    #+#             */
/*   Updated: 2021/01/10 17:47:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMITE_CLASS_HPP
# define RANDOMITE_CLASS_HPP

# include "RandomIte_decl.hpp"

namespace ft {

template <typename Spe>
VectIte<Spe>::VectIte(void) : _value(NULL) {
	return ;
}

template <typename Spe>
VectIte<Spe>::VectIte(Spe *src) : _value(src) {
	return ;
}

template <typename Spe>
VectIte<Spe>::VectIte(const VectIte &src) {
	*this = src;
}

/*
template <typename Spe>
VectIte<Spe>::VectIte(const VectIte<Spe, !is_const> &src) {
	*this = src;
}
*/

template <typename Spe>
VectIte<Spe>::~VectIte(void) {
	return ;
}

template <typename Spe>
VectIte<Spe> &VectIte<Spe>::operator=(const VectIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_value = rhs._value;
	return (*this);
}

template <typename Spe>
bool	VectIte<Spe>::operator==(const VectIte &rhs) const {
	return (this->_value == rhs._value);
}

template <typename Spe>
bool	VectIte<Spe>::operator!=(const VectIte &rhs) const {
	return (this->_value != rhs._value);
}

template <typename Spe>
bool	VectIte<Spe>::operator<(const VectIte &rhs) const {
	return (this->_value < rhs._value);
}

template <typename Spe>
bool	VectIte<Spe>::operator<=(const VectIte &rhs) const {
	return (this->_value <= rhs._value);
}

template <typename Spe>
bool	VectIte<Spe>::operator>(const VectIte &rhs) const {
	return (this->_value > rhs._value);
}

template <typename Spe>
bool	VectIte<Spe>::operator>=(const VectIte &rhs) const {
	return (this->_value >= rhs._value);
}

template <typename Spe>
VectIte<Spe> &VectIte<Spe>::operator++(void) {
	++this->_value;
	return (*this);
}

template <typename Spe>
VectIte<Spe> VectIte<Spe>::operator++(int) {
	VectIte<Spe>	tmp(*this);
	++this->_value;
	return (tmp);
}

template <typename Spe>
VectIte<Spe>& VectIte<Spe>::operator--(void) {
	--this->_value;
	return (*this);
}

template <typename Spe>
VectIte<Spe> VectIte<Spe>::operator--(int) {
	VectIte<Spe>	tmp(*this);
	--this->_value;
	return (tmp);
}

template <typename Spe>
typename VectIte<Spe>::difference_type
	VectIte<Spe>::operator-(const VectIte &rhs) {
	return (this->_value - rhs._value);
}

template <typename Spe>
VectIte<Spe> VectIte<Spe>::operator+(difference_type n) {
	return (VectIte(this->_value + n));
}

template <typename Spe>
VectIte<Spe> VectIte<Spe>::operator-(difference_type n) {
	return (VectIte(this->_value - n));
}

/*
template <typename Spe>
typename VectIte<Spe>::reference
	VectIte<Spe>::operator*(void) const {
	return (*this->_value);
}

template <typename Spe>
typename VectIte<Spe>::pointer
	VectIte<Spe>::operator->(void) const {
	return (this->_value);
}

template <typename Spe>
typename VectIte<Spe>::reference
	VectIte<Spe>::operator+=(difference_type n) {
	return (*(this->_value += n));
}

template <typename Spe>
typename VectIte<Spe>::reference
	VectIte<Spe>::operator-=(difference_type n) {
	return (*this += -n);
}

template <typename Spe>
typename VectIte<Spe>::reference
	VectIte<Spe>::operator[](difference_type n) {
	return (this->_value[n]);
}
*/

} // ******************************************************* ft namespace end //

#endif // ******************************************* RANDOMITE_CLASS_HPP end //
