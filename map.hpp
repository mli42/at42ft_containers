/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:10:55 by mli               #+#    #+#             */
/*   Updated: 2021/03/06 12:40:50 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

# include "base.hpp"
# include "map_decl.hpp"

namespace ft {

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type \
		&alloc) : _data(), _key_cmp(comp), _alloc(alloc), _size(0) {
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
map<Key, T, Compare, Alloc>&
map<Key, T, Compare, Alloc>::operator=(map const &rhs) {
	if (this == &rhs)
		return (*this);
	this->clear();
	this->_create_data_it(rhs.begin(), rhs.end());
	return (*this);
}

// ****************************** Iterators ********************************* //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::begin(void) {
	return iterator(farLeft(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::begin(void) const {
	return const_iterator(farLeft(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::end(void) {
	return iterator(farRight(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::end(void) const {
	return const_iterator(farRight(this->_data));
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rbegin(void) {
	return reverse_iterator(this->end());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rbegin(void) const {
	return const_reverse_iterator(this->end());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rend(void) {
	return reverse_iterator(this->begin());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rend(void) const {
	return const_reverse_iterator(this->begin());
}

// ******************************* Capacity ********************************* //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::size(void) const {
	return (this->_size);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::max_size(void) const {
	return (this->_max_size);
}

template<class Key, class T, class Compare, class Alloc>
bool	map<Key, T, Compare, Alloc>::empty(void) const {
	return (this->_size == 0 ? true : false);
}

// ******************************* Ele Access ******************************* //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::operator[](const key_type &k) {
	return (this->insert(value_type(k, mapped_type()))).first->second;
}

// ******************************** Modifiers ******************************* //

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
map<Key, T, Compare, Alloc>::insert(const value_type &val) {
	ft::pair<iterator, bool> res;

	res.second = !this->count(val.first);
	if (res.second == true)
		this->_btree_add(new node_type(val));
	res.first = this->find(val.first);
	return (res);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &val) {
	static_cast<void>(position);
	return this->insert(val).first;
}

template<class Key, class T, class Compare, class Alloc> template <class Ite>
void	map<Key, T, Compare, Alloc>::insert(Ite first, Ite last) {
	while (first != last)
		this->insert(*first++);
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator position) {
	this->erase(position++, position);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::erase(const key_type &k) {
	iterator element = this->find(k);

	if (element == this->end())
		return (0);
	this->_btree_rm(element._node);
	return (1);
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
	while (first != last)
		this->_btree_rm((first++)._node);
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
	node_ptr ghost = this->end()._node;

	if (this->_size == 0)
		return ;
	ghost->parent->right = NULL;
	this->_btree_clear(this->_data);
	this->_data = ghost;
	this->_size = 0;
}

// ******************************* Observers ******************************** //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::key_compare
map<Key, T, Compare, Alloc>::key_comp(void) const {
	return (key_compare());
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::value_compare
map<Key, T, Compare, Alloc>::value_comp(void) const {
	return (value_compare(key_compare()));
}

// ******************************* Operations ******************************* //

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::find(const key_type &k) {
	iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (this->_key_eq(it->first, k))
			break ;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::find(const key_type &k) const {
	const_iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (this->_key_eq(it->first, k))
			break ;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::count(const key_type &k) const {
	const_iterator	it = this->begin(), ite = this->end();
	size_type		res = 0;

	while (it != ite)
	{
		if (this->_key_eq((it++)->first, k))
		{
			++res;
			break ; // Because map can't have the same key twice (or more)
		}
	}
	return (res);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) {
	iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (!this->_key_cmp(it->first, k))
			break;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) const {
	const_iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (!this->_key_cmp(it->first, k))
			break;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::upper_bound(const key_type &k) {
	iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (this->_key_cmp(k, it->first))
			break;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::upper_bound(const key_type &k) const {
	const_iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (this->_key_cmp(k, it->first))
			break;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type &k) const {
	pair<const_iterator, const_iterator> res;

	res.first = this->lower_bound(k);
	res.second = this->upper_bound(k);
	return (res);
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type &k) {
	pair<iterator, iterator> res;

	res.first = this->lower_bound(k);
	res.second = this->upper_bound(k);
	return (res);
}

// ################################ Private ####################################

template<class Key, class T, class Compare, class Alloc> template <class Ite>
void	map<Key, T, Compare, Alloc>::_create_data_it(Ite first, Ite last) {
	this->insert(first, last);
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_create_data(size_type size, const value_type &val) {
	(void)size; (void)val;
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_cpy_content(map &src) {
	this->clear();
	node_ptr tmp = this->_data;

	this->_data = src._data;
	this->_key_cmp = src._key_cmp;
	this->_alloc = src._alloc;
	this->_size = src._size;
	src._data = tmp; src._size = 0;
	tmp = NULL;
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_btree_clear(node_ptr node) {
	if (node == NULL)
		return ;
	this->_btree_clear(node->left);
	this->_btree_clear(node->right);
	delete node;
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_btree_add(node_ptr newNode) {
	node_ptr	*parent = &this->_data;
	node_ptr	*node = &this->_data;
	node_ptr	ghost = farRight(this->_data);
	bool		side_left = -1;

	++this->_size;
	while (*node && *node != ghost)
	{
		parent = node;
		side_left = this->_key_cmp(newNode->data.first, (*node)->data.first);
		node = (side_left ? &(*node)->left : &(*node)->right);
	}
	if (*node == NULL)
	{
		newNode->parent = (*parent);
		*node = newNode;
	}
	else // if (*node == ghost)
	{
		*node = newNode;
		newNode->parent = ghost->parent;
		ghost->parent = farRight(newNode); // Using farRight(newNode)
		farRight(newNode)->right = ghost; // in case newNode isnt alone
	}
}

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::_btree_rm(node_ptr rmNode) {
	node_ptr	replaceNode = NULL;
	node_ptr	*rmPlace = &this->_data;

	--this->_size;
	if (rmNode->parent)
		rmPlace = (rmNode->parent->left == rmNode ? &rmNode->parent->left : &rmNode->parent->right);
	if (rmNode->left == NULL && rmNode->right == NULL)
		;
	else if (rmNode->left == NULL) // left == NULL && right != NULL
		replaceNode = rmNode->right;
	else // left != NULL && right ?= NULL
	{
		replaceNode = farRight(rmNode->left);
		if (replaceNode != rmNode->left)
			if ((replaceNode->parent->right = replaceNode->left))
				replaceNode->left->parent = replaceNode->parent;
	}
	if (replaceNode)
	{
		replaceNode->parent = rmNode->parent;
		if (rmNode->left && rmNode->left != replaceNode)
		{
			replaceNode->left = rmNode->left;
			replaceNode->left->parent = replaceNode;
		}
		if (rmNode->right && rmNode->right != replaceNode)
		{
			replaceNode->right = rmNode->right;
			replaceNode->right->parent = replaceNode;
		}
	}
	*rmPlace = replaceNode;
	delete rmNode;
}

template<class Key, class T, class Compare, class Alloc>
bool
map<Key, T, Compare, Alloc>::_key_eq(const key_type &k1, const key_type &k2) const {
	return (!this->_key_cmp(k1, k2) && !this->_key_cmp(k2, k1));
}

template <class Key, class T, class Compare, class Alloc>
const typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::_max_size =
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

// ################################## Other ####################################

template <class Key, class T, class Compare, class Alloc>
class	map<Key, T, Compare, Alloc>::value_compare {
	public:
	Compare comp;
	value_compare(Compare c) : comp(c) { };

	typedef bool		result_type;
	typedef value_type	first_argument_type;
	typedef value_type	second_argument_type;
	bool	operator()(const value_type &x, const value_type &y) const {
		return comp(x.first, y.first);
	}
};

} // ******************************************************* ft namespace end //

#endif // ************************************************* MAP_CLASS_HPP end //
