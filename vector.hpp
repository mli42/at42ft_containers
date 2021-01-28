/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2021/01/28 16:07:07 by mli              ###   ########.fr       */
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
	this->_create_data(size, val);
	return ;
}

template <typename T, typename Alloc> template <class Ite>
vector<T, Alloc>::vector(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
		Ite last, const allocator_type &alloc) : _data(NULL), _alloc(alloc), _size(0), _capacity(0) {
	this->_create_data(last - first, first, last);
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector const &src) : \
	_data(NULL), _alloc(allocator_type()), _size(0), _capacity(0) {
	*this = src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::~vector(void) {
	this->_destroy_data(*this);
}

template<typename T, typename Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator=(vector const &rhs) {
	if (this == &rhs)
		return (*this);
	const_iterator first = rhs.begin();
	const_iterator last = rhs.end();
	this->_create_data(last - first, first, last);
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
	return (iterator(&this->_data[this->_size]));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end(void) const {
	return (const_iterator(&this->_data[this->_size]));
}

// ******************************* Capacity ********************************* //

template<typename T, typename Alloc>
void		vector<T, Alloc>::resize(size_type size, value_type val) {
	if (size < this->_size)
	{
		while (size < this->_size)
			this->_alloc.destroy(&this->_data[--this->_size]);
	}
	else
	{
		if (size <= this->_capacity)
			;
		else if (size <= this->_capacity * 2)
			this->reserve(this->_capacity * 2);
		else
			this->reserve(size);
		while (this->_size < size)
			this->_alloc.construct(&this->_data[this->_size++], val);
	}
}

// ******************************* Ele Access ******************************* //

// ******************************** Modifiers ******************************* //

template<typename T, typename Alloc>
void		vector<T, Alloc>::push_back(const value_type &val) {
	if (this->_size == this->_capacity)
		this->resize(this->_size + 1, val);
	else
		this->_alloc.construct(&this->_data[this->_size++], val);
}

// Do not protect this function or it will not behave like the original!
template<typename T, typename Alloc>
void		vector<T, Alloc>::pop_back(void) {
	this->_alloc.destroy(&this->_data[--this->_size]);
}

template<typename T, typename Alloc>
void		vector<T, Alloc>::reserve(size_type n) {
	if (n > this->max_size())
		throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
	if (n <= this->capacity())
		return ;
	this->_create_data(n, this->begin(), this->end());
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator ite) {
	return (this->erase(ite, ite + 1));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last) {
	iterator tmp = first;
	iterator end = this->end();
	size_type deleted = last - first;

	while (last != end)
	{
		*first = *last;
		++first;
		++last;
	}
	while (deleted-- > 0)
		this->_alloc.destroy(&this->_data[--this->_size]);
	return (tmp);
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

// ################################ Private ####################################

template<typename T, typename Alloc> template <class Ite>
void	vector<T, Alloc>::_create_data(difference_type capacity, Ite first, Ite last) {
	vector<T, Alloc> res;

	if (capacity < last - first || capacity < 0)
		throw std::length_error("vector");
	res._alloc = this->_alloc;
	res._size = last - first; res._capacity = capacity;
	res._data = res._alloc.allocate(capacity);
	for (size_type i = 0; first != last; ++first)
		res._alloc.construct(&res._data[i++], *first);
	this->_destroy_data(*this);
	this->_cpy_content(res);
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::_create_data(size_type size, const value_type &val) {
	this->_destroy_data(*this);
	this->_data = this->_alloc.allocate(size);
	for (size_type i = 0; i < size; ++i)
		this->_alloc.construct(&this->_data[i], val);
	this->_size = size; this->_capacity = size;
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::_destroy_data(vector<T, Alloc> &vct) {
	if (!vct._data)
		return ;
	while (vct._size > 0)
		vct._alloc.destroy(&vct._data[--vct._size]);
	vct._alloc.deallocate(vct._data, vct._capacity);
	vct._data = NULL; vct._size = 0; vct._capacity = 0;
}

template<typename T, typename Alloc> template <class Ite, class Iterator>
void	vector<T, Alloc>::_cpy_data(Ite start, Iterator first, Iterator last) {
	while (first != last)
	{
		*start = *first;
		++start;
		++first;
	}
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::_cpy_content(vector<T, Alloc> &vct) {
	this->_data = vct._data;
	this->_alloc = vct._alloc;
	this->_size = vct._size;
	this->_capacity = vct._capacity;
	vct._data = NULL; vct._size = 0; vct._capacity = 0;
}

template <typename T, typename Alloc>
const typename vector<T, Alloc>::size_type vector<T, Alloc>::_max_size =
	std::numeric_limits<difference_type>::max() / (sizeof(value_type) / 2 ?: 1);

// ############################## Iterators ####################################

// Regular Iterator

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference
	vector<T, Alloc>::iterator::operator*(void) const {
	return (*this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::pointer
	vector<T, Alloc>::iterator::operator->(void) const {
	return (this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference
	vector<T, Alloc>::iterator::operator+=(difference_type n) {
	return (*(this->_value += n));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference
	vector<T, Alloc>::iterator::operator-=(difference_type n) {
	return (*this += -n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference
	vector<T, Alloc>::iterator::operator[](difference_type n) {
	return (this->_value[n]);
}

// Const Iterator

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference
	vector<T, Alloc>::const_iterator::operator*(void) const {
	return (*this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::pointer
	vector<T, Alloc>::const_iterator::operator->(void) const {
	return (this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference
	vector<T, Alloc>::const_iterator::operator+=(difference_type n) {
	return (*(this->_value += n));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference
	vector<T, Alloc>::const_iterator::operator-=(difference_type n) {
	return (*this += -n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference
	vector<T, Alloc>::const_iterator::operator[](difference_type n) {
	return (this->_value[n]);
}

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
