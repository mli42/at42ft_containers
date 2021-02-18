/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/02/18 15:58:09 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_ITE_CLASS_HPP
# define LST_ITE_CLASS_HPP

# include "base.hpp"

namespace ft {

template <typename Spe>
class lstIte {
	protected:
		lstNode<Spe>					*_node;
		lstIte(lstNode *src);

	public:
		typedef Spe						value_type;
		typedef ptrdiff_t				difference_type;

		lstIte(void);
		lstIte(const lstIte &src);
		virtual ~lstIte(void);
		lstIte	&operator=(lstIte const &rhs);

		bool	operator==(const lstIte &rhs) const;
		bool	operator!=(const lstIte &rhs) const;

		lstIte<Spe>	&operator++(void);
		lstIte<Spe>	operator++(int);
		lstIte<Spe>	&operator--(void);
		lstIte<Spe>	operator--(int);

		reference	operator*(void) const;
		pointer		operator->(void) const;

		template <class, class>
		friend class list;
}; // *************************************************** class lstIte end //

template <typename Spe>
lstIte<Spe>::lstIte(void) : _node(NULL) { return ; }

template <typename Spe>
lstIte<Spe>::lstIte(lstNode *src) : _node(src) { return ; }

template <typename Spe>
lstIte<Spe>::lstIte(const lstIte &src) { *this = src; }

template <typename Spe>
lstIte<Spe>::~lstIte(void) { return ; }

template <typename Spe>
lstIte<Spe> &lstIte<Spe>::operator=(const lstIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_node = rhs._node;
	return (*this);
}

template <typename Spe>
bool	lstIte<Spe>::operator==(const lstIte &rhs) const {
	return (this->_node == rhs._node);
}

template <typename Spe>
bool	lstIte<Spe>::operator!=(const lstIte &rhs) const {
	return (this->_node != rhs._node);
}

template <typename Spe>
lstIte<Spe> &lstIte<Spe>::operator++(void) {
	this->_node = this->_node->next;
	return (*this);
}

template <typename Spe>
lstIte<Spe> lstIte<Spe>::operator++(int) {
	lstIte<Spe>	tmp(*this);
	++(*this);
	return (tmp);
}

template <typename Spe>
lstIte<Spe>& lstIte<Spe>::operator--(void) {
	this->_node = this->_node->prev;
	return (*this);
}

template <typename Spe>
lstIte<Spe> lstIte<Spe>::operator--(int) {
	lstIte<Spe>	tmp(*this);
	--(*this);
	return (tmp);
}

template <typename Spe>
typename lstIte<Spe>::reference lstIte<Spe>::operator*(void) const {
	return (this->_node->data);
}

template <typename Spe>
typename lstIte<Spe>::pointer lstIte<Spe>::operator->(void) const {
	return &this->operator*();
}

} // ******************************************************* ft namespace end //

#endif // ********************************************* LST_ITE_CLASS_HPP end //
