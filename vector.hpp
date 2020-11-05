/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/11/05 22:14:18 by mli              ###   ########.fr       */
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

template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type size, const value_type &val,
	const allocator_type &alloc) : \
	_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
	(void)size; (void)val;
//	this->resize(size, val);
	return ;
}

/*
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		const allocator_type &alloc = allocator_type());
*/
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

// ****************************** Iterators ********************************* //

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin(void) {
	return (iterator(this->_data));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin(void) const {
	return (const_iterator(this->_data));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end(void) {
	return (iterator(&this->_data[this->size]));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end(void) const {
	return (const_iterator(&this->_data[this->size]));
}

// ******************************* Capacity ********************************* //

template<typename T, typename Alloc>
void	vector<T, Alloc>::_create_data(size_type size, value_type val) {
	this->_data = this->_alloc.allocate(size);
	for (size_type i = 0; i < size; ++i)
		this->_alloc.construct(&this->_data[i], val);
	this->_size = size; this->_capacity = size;
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::_destroy_data(void) {
	if (!this->_data)
		return ;
	for (size_type i = 0; i < this->size; ++i)
		this->_alloc.destroy(&this->_data[i]);
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_data = NULL; this->_size = 0; this->_capacity = 0;
}

template<typename T, typename Alloc> template <class InputIterator>
void	vector<T, Alloc>::_cpy_data(InputIterator first, InputIterator last) {
	size_type i = 0;
	while (first != last)
	{
		this->_data[i] = *first;
		++first;
		++i;
	}
}

template<typename T, typename Alloc>
void		vector<T, Alloc>::resize(size_type size, value_type val) {
	if (size < this->_size)
	{
		while (size < this->_size)
			this->_alloc.destroy(this->_data[--this->_size]);
	}
	else if (size <= this->_capacity)
	{
		while (this->_size < size)
			this->_alloc.construct(this->_data[this->_size++], val);
	}
	else
	{
		vector<T, Alloc> tmp(size, val, this->_alloc);
		tmp._cpy_data(this->begin(), this->end());
	}
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator ite) {
	return (this->erase(ite, ite + 1));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last) {
	iterator end = this->end();
	size_type deleted = last - first;

	while (last != end)
	{
		*first = *(++last);
		++first;
	}
	while (deleted-- > 0)
		this->_alloc.destroy(&this->_data[--this->_size]);
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
vector<T, Alloc>::VectIte<Spe>::VectIte(const pointer &src) : _value(src) {
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

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>&
	vector<T, Alloc>::VectIte<Spe>::operator++(void) {
	++this->_value;
	return (*this);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>
	vector<T, Alloc>::VectIte<Spe>::operator++(int) {
	VectIte<Spe>	tmp(*this);
	++this->_value;
	return (tmp);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>&
	vector<T, Alloc>::VectIte<Spe>::operator--(void) {
	--this->_value;
	return (*this);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>
	vector<T, Alloc>::VectIte<Spe>::operator--(int) {
	VectIte<Spe>	tmp(*this);
	--this->_value;
	return (tmp);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>
	vector<T, Alloc>::VectIte<Spe>::operator+(difference_type n) {
	return (VectIte(this->_value + n));
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>
	vector<T, Alloc>::VectIte<Spe>::operator-(difference_type n) {
	return (VectIte(this->_value - n));
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>::difference_type
	vector<T, Alloc>::VectIte<Spe>::operator-(const VectIte &rhs) {
	return (this->_value - rhs._value);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>::reference
	vector<T, Alloc>::VectIte<Spe>::operator+=(difference_type n) {
	return (this->_value += n);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>::reference
	vector<T, Alloc>::VectIte<Spe>::operator-=(difference_type n) {
	return (*this += -n);
}

template <typename T, typename Alloc> template <typename Spe>
typename vector<T, Alloc>::template VectIte<Spe>::reference
	vector<T, Alloc>::VectIte<Spe>::operator[](difference_type n) {
	return (this->_value[n]);
}

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
