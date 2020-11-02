/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/11/02 20:52:06 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

# include "base.hpp"
# include "vector_decl.hpp"

namespace ft {

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type &alloc) : \
	_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
	return ;
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector const &src) {
	*this = src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::~vector(void) {
	return ;
}

template<typename T, typename Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator=(vector const &rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size(void) const {
	return (this->_size);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity(void) const {
	return (this->_capacity);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size(void) const {
	return (_max_size);
}

template <typename T, typename Alloc>
const typename vector<T, Alloc>::size_type vector<T, Alloc>::_max_size =
	std::numeric_limits<difference_type>::max() / (sizeof(value_type) / 2 ?: 1);

// ############################## Iterators ####################################

template <typename T, typename Alloc> template <typename Spe>
vector<T, Alloc>::VectIte<Spe>::VectIte(void) : _value(NULL) {
	return ;
}

template <typename T, typename Alloc> template <typename Spe>
vector<T, Alloc>::VectIte<Spe>::VectIte(const VectIte &src) {
	*this = src;
}

template <typename T, typename Alloc> template <typename Spe>
vector<T, Alloc>::VectIte<Spe>::~VectIte(void) {
	return ;
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>&
	vector<T, Alloc>::VectIte<Spe>::operator=(const VectIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_value = rhs._value;
	return (*this);
}

template <typename T, typename Alloc> template <typename Spe>
bool	vector<T, Alloc>::VectIte<Spe>::operator==(const VectIte &rhs) const {
	return (this->_value == rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
bool	vector<T, Alloc>::VectIte<Spe>::operator!=(const VectIte &rhs) const {
	return (this->_value != rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
bool	vector<T, Alloc>::VectIte<Spe>::operator<(const VectIte &rhs) const {
	return (this->_value < rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
bool	vector<T, Alloc>::VectIte<Spe>::operator<=(const VectIte &rhs) const {
	return (this->_value <= rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
bool	vector<T, Alloc>::VectIte<Spe>::operator>(const VectIte &rhs) const {
	return (this->_value > rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
bool	vector<T, Alloc>::VectIte<Spe>::operator>=(const VectIte &rhs) const {
	return (this->_value >= rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>::reference
	vector<T, Alloc>::VectIte<Spe>::operator*(void) const {
	return (*this->_value);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>::pointer
	vector<T, Alloc>::VectIte<Spe>::operator->(void) const {
	return (this->_value);
}

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
