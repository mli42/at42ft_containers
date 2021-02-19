/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/02/19 23:50:50 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_ITE_CLASS_HPP
# define LST_ITE_CLASS_HPP

# include "base.hpp"

namespace ft {

template <typename Spe, typename node_type>
class lstIte {
	protected:
		node_type						*_node;
		lstIte(const node_type *src);

	public:
		typedef Spe						value_type;
		typedef ptrdiff_t				difference_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;

		lstIte(void);
		lstIte(const lstIte &src);
		virtual ~lstIte(void);
		lstIte	&operator=(lstIte const &rhs);

		bool	operator==(const lstIte &rhs) const;
		bool	operator!=(const lstIte &rhs) const;

		lstIte		&operator++(void);
		lstIte		operator++(int);
		lstIte		&operator--(void);
		lstIte		operator--(int);

		reference	operator*(void) const;
		pointer		operator->(void) const;

		/*
		operator lstIte<const Spe, node_type>(void) const {
			return lstIte<const Spe, node_type>(this->_node);
		}
		*/

		template <class, class>
		friend class list;

}; // *************************************************** class lstIte end //

template <typename Spe, typename node_type>
lstIte<Spe, node_type>::lstIte(void) : _node(NULL) { return ; }

template <typename Spe, typename node_type>
lstIte<Spe, node_type>::lstIte(const node_type *src) {
	this->_node->data = src->data;
	this->_node->next = src->next;
	this->_node->prev = src->prev;
}

template <typename Spe, typename node_type>
lstIte<Spe, node_type>::lstIte(const lstIte &src) { *this = src; }

template <typename Spe, typename node_type>
lstIte<Spe, node_type>::~lstIte(void) { return ; }

template <typename Spe, typename node_type>
lstIte<Spe, node_type> &lstIte<Spe, node_type>::operator=(const lstIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_node = rhs._node;
	return (*this);
}

template <typename Spe, typename node_type>
bool	lstIte<Spe, node_type>::operator==(const lstIte &rhs) const {
	return (this->_node == rhs._node);
}

template <typename Spe, typename node_type>
bool	lstIte<Spe, node_type>::operator!=(const lstIte &rhs) const {
	return (this->_node != rhs._node);
}

template <typename Spe, typename node_type>
lstIte<Spe, node_type> &lstIte<Spe, node_type>::operator++(void) {
	this->_node = this->_node->next;
	return (*this);
}

template <typename Spe, typename node_type>
lstIte<Spe, node_type> lstIte<Spe, node_type>::operator++(int) {
	lstIte<Spe, node_type>	tmp(*this);
	++(*this);
	return (tmp);
}

template <typename Spe, typename node_type>
lstIte<Spe, node_type>& lstIte<Spe, node_type>::operator--(void) {
	this->_node = this->_node->prev;
	return (*this);
}

template <typename Spe, typename node_type>
lstIte<Spe, node_type> lstIte<Spe, node_type>::operator--(int) {
	lstIte<Spe, node_type>	tmp(*this);
	--(*this);
	return (tmp);
}

template <typename Spe, typename node_type>
typename lstIte<Spe, node_type>::reference lstIte<Spe, node_type>::operator*(void) const {
	return (this->_node->data);
}

template <typename Spe, typename node_type>
typename lstIte<Spe, node_type>::pointer lstIte<Spe, node_type>::operator->(void) const {
	return &this->operator*();
}

} // ******************************************************* ft namespace end //

#endif // ********************************************* LST_ITE_CLASS_HPP end //
