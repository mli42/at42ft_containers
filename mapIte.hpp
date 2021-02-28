/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:47:56 by mli               #+#    #+#             */
/*   Updated: 2021/02/28 15:53:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITE_CLASS_HPP
# define MAP_ITE_CLASS_HPP

# include "base.hpp"

namespace ft {

template <typename T, typename node_type>
class mapIte {
	protected:
		node_type						*_node;
		mapIte(node_type *src);

	public:
		typedef T						value_type;
		typedef ptrdiff_t				difference_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;

		mapIte(void);
		mapIte(const mapIte &src);
		virtual ~mapIte(void);
		mapIte	&operator=(mapIte const &rhs);

		template <class U> bool	operator==(const mapIte<U, node_type> &rhs) const;
		template <class U> bool	operator!=(const mapIte<U, node_type> &rhs) const;

		mapIte		&operator++(void);
		mapIte		operator++(int);
		mapIte		&operator--(void);
		mapIte		operator--(int);

		reference	operator*(void) const;
		pointer		operator->(void) const;

		operator mapIte<const T, node_type>(void) const {
			return mapIte<const T, node_type>(this->_node);
		}

		template <class, class, class, class>
		friend class map;

		template <class, class>
		friend class mapIte;

}; // ****************************************************** class mapIte end //

template <typename T, typename node_type>
mapIte<T, node_type>::mapIte(void) : _node(NULL) { return ; }

template <typename T, typename node_type>
mapIte<T, node_type>::mapIte(node_type *src) { this->_node = src; }

template <typename T, typename node_type>
mapIte<T, node_type>::mapIte(const mapIte &src) { *this = src; }

template <typename T, typename node_type>
mapIte<T, node_type>::~mapIte(void) { return ; }

template <typename T, typename node_type>
mapIte<T, node_type> &mapIte<T, node_type>::operator=(const mapIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_node = rhs._node;
	return (*this);
}

template <typename T, typename node_type> template <class U>
bool	mapIte<T, node_type>::operator==(const mapIte<U, node_type> &rhs) const {
	return (this->_node == rhs._node);
}

template <typename T, typename node_type> template <class U>
bool	mapIte<T, node_type>::operator!=(const mapIte<U, node_type> &rhs) const {
	return (this->_node != rhs._node);
}

template <typename T, typename node_type>
mapIte<T, node_type> &mapIte<T, node_type>::operator++(void) {
	if (this->_node->right != NULL)
		this->_node = farLeft(this->_node->right);
	else
	{
		node_type	*child = this->_node;

		this->_node = this->_node->parent;
		while (this->_node && child == this->_node->right)
		{
			child = this->_node;
			this->_node = this->_node->parent;
		}
	}
	return (*this);
}

template <typename T, typename node_type>
mapIte<T, node_type> mapIte<T, node_type>::operator++(int) {
	mapIte	tmp(*this);
	++(*this);
	return (tmp);
}

template <typename T, typename node_type>
mapIte<T, node_type>& mapIte<T, node_type>::operator--(void) {
	if (this->_node->left != NULL)
		this->_node = farRight(this->_node->left);
	else
	{
		node_type	*child = this->_node;

		this->_node = this->_node->parent;
		while (this->_node && child == this->_node->left)
		{
			child = this->_node;
			this->_node = this->_node->parent;
		}
	}
	return (*this);
}

template <typename T, typename node_type>
mapIte<T, node_type> mapIte<T, node_type>::operator--(int) {
	mapIte	tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T, typename node_type>
typename mapIte<T, node_type>::reference mapIte<T, node_type>::operator*(void) const {
	return (this->_node->data);
}

template <typename T, typename node_type>
typename mapIte<T, node_type>::pointer mapIte<T, node_type>::operator->(void) const {
	return &this->operator*();
}

} // ******************************************************* ft namespace end //

#endif // ********************************************* MAP_ITE_CLASS_HPP end //
