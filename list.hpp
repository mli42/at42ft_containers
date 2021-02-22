/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:04:22 by mli               #+#    #+#             */
/*   Updated: 2021/02/22 12:33:38 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CLASS_HPP
# define LIST_CLASS_HPP

# include "base.hpp"
# include "list_decl.hpp"

namespace ft {

template <typename T, typename Alloc>
list<T, Alloc>::list(const allocator_type &alloc) : \
	_data(), _alloc(alloc), _size(0) {
	return ;
}

template <typename T, typename Alloc>
list<T, Alloc>::list(size_type size, const value_type &val, const allocator_type &alloc) : \
	_data(), _alloc(alloc), _size(0) {
	this->_create_data(size, val);
	return ;
}

template <typename T, typename Alloc> template <class Ite>
list<T, Alloc>::list(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
		Ite last, const allocator_type &alloc) : _data(), _alloc(alloc), _size(0) {
	this->_create_data_it(first, last);
}

template<typename T, typename Alloc>
list<T, Alloc>::list(list const &src) : _data(), _alloc(allocator_type()), _size(0) {
	*this = src;
}

template<typename T, typename Alloc>
list<T, Alloc>::~list(void) {
	this->_destroy_data();
}

template<typename T, typename Alloc>
list<T, Alloc>	&list<T, Alloc>::operator=(list const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_create_data_it(rhs.begin(), rhs.end());
	return (*this);
}

// ****************************** Iterators ********************************* //

template<typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::begin(void) {
	return iterator(this->_data.next);
}

template<typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::begin(void) const {
	return const_iterator(this->_data.next);
}

template<typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::end(void) {
	return iterator(&this->_data);
}

template<typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::end(void) const {
	return const_iterator(this->_data.next->prev);
}

template<typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rbegin(void) {
	return reverse_iterator(this->end());
}

template<typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rbegin(void) const {
	return const_reverse_iterator(this->end());
}

template<typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rend(void) {
	return reverse_iterator(this->begin());
}

template<typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rend(void) const {
	return const_reverse_iterator(this->begin());
}

// ******************************* Capacity ********************************* //

template<typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::size(void) const {
	return (this->_size);
}

template<typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::max_size(void) const {
	return (_max_size);
}

template<typename T, typename Alloc>
bool	list<T, Alloc>::empty(void) const {
	return (this->_size == 0 ? true : false);
}

// ******************************* Ele Access ******************************* //

template<typename T, typename Alloc> typename list<T, Alloc>::
reference		list<T, Alloc>::front(void) {
	return *this->begin();
}

template<typename T, typename Alloc> typename list<T, Alloc>::
const_reference	list<T, Alloc>::front(void) const {
	return *this->begin();
}

template<typename T, typename Alloc> typename list<T, Alloc>::
reference		list<T, Alloc>::back(void) {
	return this->_data.prev->data;
}

template<typename T, typename Alloc> typename list<T, Alloc>::
const_reference	list<T, Alloc>::back(void) const {
	return this->_data.prev->data;
}

// ******************************** Modifiers ******************************* //

template<typename T, typename Alloc> template <class Ite>
void	list<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first, Ite last) {
	list newList(first, last);

	this->swap(newList);
}

template<typename T, typename Alloc>
void	list<T, Alloc>::assign(size_type n, const value_type &val) {
	list newList(n, val);

	this->swap(newList);
}

template<typename T, typename Alloc>
void		list<T, Alloc>::push_front(const value_type &val) {
	node_type	*newNode = new node_type;

	++this->_size;
	newNode->data = val;
	newNode->next = this->_data.next;
	newNode->prev = &this->_data;
	this->_data.next->prev = newNode;
	this->_data.next = newNode;
}

template<typename T, typename Alloc>
void		list<T, Alloc>::pop_front(void) {
	node_type	*oldNode = this->_data.next;

	if (this->empty())
		return ;
	--this->_size;
	this->_data.next = oldNode->next;
	this->_data.next->prev = &this->_data;
	delete oldNode;
}

template<typename T, typename Alloc>
void		list<T, Alloc>::push_back(const value_type &val) {
	node_type	*newNode = new node_type;

	++this->_size;
	newNode->data = val;
	newNode->next = &this->_data;
	newNode->prev = this->_data.prev;
	this->_data.prev->next = newNode;
	this->_data.prev = newNode;
}

template<typename T, typename Alloc>
void		list<T, Alloc>::pop_back(void) {
	node_type	*oldNode = this->_data.prev;

	if (this->empty())
		return ;
	--this->_size;
	this->_data.prev = oldNode->prev;
	this->_data.prev->next = &this->_data;
	delete oldNode;
}

template<typename T, typename Alloc> typename list<T, Alloc>::
iterator	list<T, Alloc>::insert(iterator position, const value_type &val) {
	this->insert(position, 1, val);
	return (--position);
}

template<typename T, typename Alloc>
void	list<T, Alloc>::insert(iterator position, size_type n, const value_type &val) {
	node_type *after = position._node;
	node_type *after_end = this->_data.prev;

	--position;
	position._node->next = &this->_data;
	this->_data.prev = position._node;
	while (n-- != 0)
		this->push_back(val);
	if (after == &this->_data)
		return ;
	after->prev = this->_data.prev;
	this->_data.prev->next = after;
	this->_data.prev = after_end;
}

template<typename T, typename Alloc> template <class Ite>
void	list<T, Alloc>::insert(iterator position, Ite first, typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type last) {
	node_type *after = position._node;
	node_type *after_end = this->_data.prev;

	--position;
	position._node->next = &this->_data;
	this->_data.prev = position._node;
	while (first != last)
		this->push_back(*first++);
	if (after == &this->_data)
		return ;
	after->prev = this->_data.prev;
	this->_data.prev->next = after;
	this->_data.prev = after_end;
}

template<typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::erase(iterator ite) {
	return (this->erase(ite++, ite));
}

template<typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::erase(iterator first, iterator last) {
	node_type *last_del = last._node;
	node_type *before_del = first._node->prev;

	before_del->next = last_del;
	last_del->prev = before_del;
	while (first != last)
	{
		--this->_size;
		delete (first++)._node;
	}
	return last;
}

template<typename T, typename Alloc>
void	list<T, Alloc>::swap(list &x) {
	list<T, Alloc> tmp;

	tmp._cpy_content(x);
	x._cpy_content(*this);
	this->_cpy_content(tmp);
}

template<typename T, typename Alloc>
void	list<T, Alloc>::clear(void) {
	iterator it = this->begin(), ite = this->end(), tmp;

	while (it != ite)
	{
		tmp = it++;
		delete tmp._node;
	}
	this->_size = 0; this->_data.initialize();
}

template<typename T, typename Alloc>
void	list<T, Alloc>::resize(size_type size, const value_type &val) {
	while (size < this->_size)
		this->pop_back();
	while (size > this->_size)
		this->push_back(val);
}

// ******************************* Operations ******************************* //

template<typename T, typename Alloc>
void	list<T, Alloc>::reverse(void) {
	iterator	it = iterator(&this->_data);
	size_type	size = this->_size + 1;
	node_type	*tmp;

	while (size != 0)
	{
		tmp = it._node->next;
		it._node->next = it._node->prev;
		it._node->prev = tmp;
		++it; --size;
	}
}

// ################################ Private ####################################

template<typename T, typename Alloc> template <class Ite>
void	list<T, Alloc>::_create_data_it(Ite first, Ite last) {
	iterator it = this->begin(), ite = this->end();

	while (it != ite && first != last)
		*it++ = *first++;
	--it;
	while (it != --this->end())
		this->pop_back();
	while (first != last)
		this->push_back(*first++);
}

template<typename T, typename Alloc>
void	list<T, Alloc>::_create_data(size_type size, const value_type &val) {
	iterator it = this->begin(), ite = this->end();

	while (it != ite && size != 0)
	{
		*it++ = val;
		--size;
	}
	--it;
	while (it != --this->end())
		this->pop_back();
	while (size != 0)
	{
		this->push_back(val);
		--size;
	}
}

template<typename T, typename Alloc>
void	list<T, Alloc>::_destroy_data(void) {
	if (this->empty())
		return ;
	this->clear();
}

template<typename T, typename Alloc>
void	list<T, Alloc>::_cpy_content(list<T, Alloc> &src) {
	this->_data = src._data;
	this->_alloc = src._alloc;
	this->_size = src._size;
	src._data.initialize(); src._size = 0;
}

template <typename T, typename Alloc>
const typename list<T, Alloc>::size_type list<T, Alloc>::_max_size =
	std::numeric_limits<difference_type>::max() / (sizeof(node_type) / 2 ?: 1);

// ####################### Non-member function overloads #######################

template <class T, class Alloc>
bool	operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool	operator< (const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool	operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool	operator> (const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
	return !(lhs < rhs);
}

template <class T, class Alloc>
void	swap(list<T, Alloc> &x, list<T, Alloc> &y) { x.swap(y); }

} // ******************************************************* ft namespace end //

#endif // ************************************************ LIST_CLASS_HPP end //
