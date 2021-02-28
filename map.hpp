/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:10:55 by mli               #+#    #+#             */
/*   Updated: 2021/02/28 15:35:45 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

# include "base.hpp"
# include "map_decl.hpp"

namespace ft {

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc) : \
		_data(), _key_cmp(comp), _alloc(alloc), _size(0) {
	this->_data = new node_type;
	return ;
}

template <class Key, class T, class Compare, class Alloc> template <class Ite>
map<Key, T, Compare, Alloc>::map(
	typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
	Ite last, const key_compare &comp, const allocator_type &alloc) : \
		_data(), _key_cmp(comp), _alloc(alloc), _size(0) {
	this->_data = new node_type;
	this->_create_data_it(first, last);
}

template<class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(map const &src) : \
		_data(), _key_cmp(key_compare()), _alloc(allocator_type()), _size(0) {
	this->_data = new node_type;
	*this = src;
}

template<class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::~map(void) {
	this->clear();
	delete this->_data;
}

template<class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>::operator=(map const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_create_data_it(rhs.begin(), rhs.end());
	return (*this);
}

// ****************************** Iterators ********************************* //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin(void) {
	return iterator(farLeft(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin(void) const {
	return const_iterator(farLeft(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end(void) {
	return iterator(farRight(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::end(void) const {
	return const_iterator(farRight(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin(void) {
	return reverse_iterator(this->end());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin(void) const {
	return const_reverse_iterator(this->end());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rend(void) {
	return reverse_iterator(this->begin());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rend(void) const {
	return const_reverse_iterator(this->begin());
}

// ******************************* Capacity ********************************* //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::size(void) const {
	return (this->_size);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::max_size(void) const {
	return (this->_max_size);
}

template<class Key, class T, class Compare, class Alloc>
bool	map<Key, T, Compare, Alloc>::empty(void) const {
	return (this->_size == 0 ? true : false);
}

// ******************************* Ele Access ******************************* //

// ******************************** Modifiers ******************************* //

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator position) {
	this->erase(position++, position);
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
	(void)first; (void)last;
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::swap(map &x) {
	map tmp;

	tmp._cpy_content(x);
	x._cpy_content(*this);
	this->_cpy_content(tmp);
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::clear(void) {
	;
}

// ******************************* Operations ******************************* //

// ################################ Private ####################################

template<class Key, class T, class Compare, class Alloc> template <class Ite>
void	map<Key, T, Compare, Alloc>::_create_data_it(Ite first, Ite last) {
	(void)first; (void)last;
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_create_data(size_type size, const value_type &val) {
	(void)size; (void)val;
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_cpy_content(map<Key, T, Compare, Alloc> &src) {
	this->_data = src._data;
	this->_key_cmp = src._key_cmp;
	this->_alloc = src._alloc;
	this->_size = src._size;
	src._data->initialize(); src._size = 0;
}

template <class Key, class T, class Compare, class Alloc>
const typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::_max_size =
	std::numeric_limits<difference_type>::max() / (sizeof(node_type) / 2 ?: 1);

// ####################### Non-member function overloads #######################

template <class Key, class T, class Compare, class Alloc>
bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator< (const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
	return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator> (const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
	return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
	x.swap(y);
}

} // ******************************************************* ft namespace end //

#endif // ************************************************* MAP_CLASS_HPP end //
