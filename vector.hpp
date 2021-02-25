/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2021/02/25 12:06:25 by mli              ###   ########.fr       */
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
	this->_create_data(ft::itlen(first, last), first, last);
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector const &src) : \
	_data(NULL), _alloc(allocator_type()), _size(0), _capacity(0) {
	*this = src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::~vector(void) {
	this->_destroy_data();
}

template<typename T, typename Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator=(vector const &rhs) {
	if (this == &rhs)
		return (*this);
	const_iterator first = rhs.begin();
	const_iterator last = rhs.end();
	size_type len = ft::itlen(first, last);
	this->_create_data((len > this->_capacity) ? len : this->_capacity, first, last);
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

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin(void) {
	return (reverse_iterator(&this->_data[this->_size]));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin(void) const {
	return (const_reverse_iterator(&this->_data[this->_size]));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(void) {
	return (reverse_iterator(this->_data));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend(void) const {
	return (const_reverse_iterator(this->_data));
}

// ******************************* Capacity ********************************* //

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

template<typename T, typename Alloc>
void		vector<T, Alloc>::reserve(size_type n) {
	if (n > this->max_size())
		throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
	if (n <= this->capacity())
		return ;
	this->_create_data(n, this->begin(), this->end());
}

template<typename T, typename Alloc>
void		vector<T, Alloc>::resize(size_type size, value_type val) {
	if (size < this->_size)
	{
		while (size < this->_size)
			this->_alloc.destroy(&this->_data[--this->_size]);
	}
	else
	{
		size_type const &lambda = (__APPLE__ ? this->_capacity : this->_size);

		if (size <= this->_capacity)
			;
		else if (size <= lambda * 2)
			this->reserve(lambda * 2);
		else
			this->reserve(size);
		while (this->_size < size)
			this->_alloc.construct(&this->_data[this->_size++], val);
	}
}

template<typename T, typename Alloc>
bool	vector<T, Alloc>::empty(void) const {
	return (this->_size == 0 ? true : false);
}

// ******************************* Ele Access ******************************* //

template<typename T, typename Alloc> typename vector<T, Alloc>::
reference		vector<T, Alloc>::operator[](size_type n) {
	return this->_data[n];
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
const_reference	vector<T, Alloc>::operator[](size_type n) const {
	return this->_data[n];
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
reference		vector<T, Alloc>::at(size_type n) {
	if (n < this->_size)
		return ((*this)[n]);
	std::ostringstream ostr;

	ostr << "vector";
	if (!__APPLE__)
	{
		ostr << "::_M_range_check: __n (which is " << n
			<< ") >= this->size() (which is " << this->_size << ")";
	}
	throw std::out_of_range(ostr.str());
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
const_reference	vector<T, Alloc>::at(size_type n) const {
	if (n < this->_size)
		return ((*this)[n]);
	std::ostringstream ostr;

	ostr << "vector";
	if (!__APPLE__)
	{
		ostr << "::_M_range_check: __n (which is " << n
			<< ") >= this->size() (which is " << this->_size << ")";
	}
	throw std::out_of_range(ostr.str());
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
reference		vector<T, Alloc>::front(void) {
	return (*this)[0];
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
const_reference	vector<T, Alloc>::front(void) const {
	return (*this)[0];
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
reference		vector<T, Alloc>::back(void) {
	return (*this)[this->_size - 1];
}

template<typename T, typename Alloc> typename vector<T, Alloc>::
const_reference	vector<T, Alloc>::back(void) const {
	return (*this)[this->_size - 1];
}

// ******************************** Modifiers ******************************* //

template<typename T, typename Alloc> template <class Ite>
void	vector<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first, Ite last) {
	size_type size = ft::itlen(first, last);

	if (size > this->_capacity)
		this->_create_data(size, first, last);
	else
	{
		this->clear();
		while (first != last)
			this->_alloc.construct(&this->_data[this->_size++], *first++);
	}
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::assign(size_type n, const value_type &val) {
	if (n > this->_capacity)
		this->_create_data(n, val);
	else
	{
		this->clear();
		while (this->_size < n)
			this->_alloc.construct(&this->_data[this->_size++], val);
	}
}

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

template<typename T, typename Alloc> typename vector<T, Alloc>::
iterator	vector<T, Alloc>::insert(iterator position, const value_type &val) {
	difference_type idx = position - this->begin();

	this->insert(position, 1, val);
	return (iterator(this->begin() + idx));
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val) {
	difference_type const	idx = position - this->begin();
	difference_type const	old_end_idx = this->end() - this->begin();
	iterator				old_end, end;

	this->resize(this->_size + n);

	end = this->end();
	position = this->begin() + idx;
	old_end = this->begin() + old_end_idx;
	while (old_end != position)
		*--end = *--old_end;
	while (n-- > 0)
		*position++ = val;
}

template<typename T, typename Alloc> template <class Ite>
void	vector<T, Alloc>::insert(iterator position, Ite first, typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type last) {
	difference_type const	idx = position - this->begin();
	difference_type const	old_end_idx = this->end() - this->begin();
	iterator				old_end, end;

	this->resize(this->_size + (ft::itlen(first, last)));

	end = this->end();
	position = this->begin() + idx;
	old_end = this->begin() + old_end_idx;
	while (old_end != position)
		*--end = *--old_end;
	while (first != last)
		*position++ = *first++;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator ite) {
	return (this->erase(ite, ite + 1));
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last) {
	iterator tmp = first;
	iterator end = this->end();
	size_type deleted = ft::itlen(first, last);

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
void	vector<T, Alloc>::swap(vector &x) {
	vector<T, Alloc> tmp;

	tmp._cpy_content(x);
	x._cpy_content(*this);
	this->_cpy_content(tmp);
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::clear(void) {
	while (this->_size > 0)
		this->_alloc.destroy(&this->_data[--this->_size]);
}

// ################################ Private ####################################

template<typename T, typename Alloc> template <class Ite>
void	vector<T, Alloc>::_create_data(difference_type capacity, Ite first, Ite last) {
	vector<T, Alloc> res;
	difference_type len = ft::itlen(first, last);

	if (capacity < len || capacity < 0)
		__APPLE__ ? throw std::length_error("vector") : throw std::bad_alloc();
	res._alloc = this->_alloc;
	res._size = len; res._capacity = capacity;
	res._data = res._alloc.allocate(capacity);
	for (size_type i = 0; first != last; ++first)
		res._alloc.construct(&res._data[i++], *first);
	this->_destroy_data();
	this->_cpy_content(res);
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::_create_data(size_type size, const value_type &val) {
	this->_destroy_data();
	this->_data = this->_alloc.allocate(size);
	for (size_type i = 0; i < size; ++i)
		this->_alloc.construct(&this->_data[i], val);
	this->_size = size; this->_capacity = size;
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::_destroy_data(void) {
	if (!this->_data)
		return ;
	this->clear();
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_data = NULL; this->_size = 0; this->_capacity = 0;
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
typename vector<T, Alloc>::iterator&
	vector<T, Alloc>::iterator::operator+=(difference_type n) {
	this->_value += n; return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator&
	vector<T, Alloc>::iterator::operator-=(difference_type n) {
	this->_value -= n; return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference
	vector<T, Alloc>::iterator::operator[](difference_type n) const {
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
typename vector<T, Alloc>::const_iterator&
	vector<T, Alloc>::const_iterator::operator+=(difference_type n) {
	this->_value += n; return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator&
	vector<T, Alloc>::const_iterator::operator-=(difference_type n) {
	this->_value -= n; return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference
	vector<T, Alloc>::const_iterator::operator[](difference_type n) const {
	return (this->_value[n]);
}

// ####################### Non-member function overloads #######################

template <class T, class Alloc>
bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool	operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool	operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return !(lhs < rhs);
}

template <class T, class Alloc>
void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
