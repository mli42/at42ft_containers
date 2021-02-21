/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIte.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/02/21 14:31:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITE_CLASS_HPP
# define REVERSEITE_CLASS_HPP

# include "base.hpp"
# include "RandomIte.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
	protected:
		typedef Iterator	super;
		Iterator _base;
	public:
		typedef Iterator							iterator_type;
		typedef typename super::difference_type		difference_type;
		typedef typename super::reference			reference;
		typedef typename super::pointer				pointer;

		reverse_iterator(void);
		explicit reverse_iterator(Iterator x);
		template <class U> reverse_iterator(const reverse_iterator<U> &u);
		template <class U> reverse_iterator &operator=(const reverse_iterator<U> &u);
		Iterator base(void) const { return this->_base; };

		reference			operator*(void) const { return (--super(this->_base)).operator*(); };
		pointer				operator->(void) const { return &this->operator*(); };

		reverse_iterator	&operator++(void) { this->_base.operator--(); return *this; };
		reverse_iterator	operator++(int) { return reverse_iterator(this->_base.operator--(0)); };
		reverse_iterator	&operator--(void) { this->_base.operator++(); return *this; };
		reverse_iterator	operator--(int) { return reverse_iterator(this->_base.operator++(0)); };

		template <class U>
		difference_type		operator-(const reverse_iterator<U> &u) { return u.base().operator-(this->_base); };
		reverse_iterator	operator+ (difference_type n) const { return reverse_iterator(this->_base.operator-(n)); };
		reverse_iterator	&operator+=(difference_type n) { this->_base.operator-=(n); return *this; };
		reverse_iterator	operator- (difference_type n) const { return reverse_iterator(this->_base.operator+(n)); };
		reverse_iterator	&operator-=(difference_type n) { this->_base.operator+=(n); return *this; };
		reference			operator[](difference_type n) const { return *this->operator+(n); };

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs)
			{ return rhs.operator+(n); };

		template <class U> bool	operator==(const reverse_iterator<U> &rhs) const { return this->_base.operator==(rhs.base()); };
		template <class U> bool	operator!=(const reverse_iterator<U> &rhs) const { return this->_base.operator!=(rhs.base()); };
		template <class U> bool	operator< (const reverse_iterator<U> &rhs) const { return this->_base.operator> (rhs.base()); };
		template <class U> bool	operator<=(const reverse_iterator<U> &rhs) const { return this->_base.operator>=(rhs.base()); };
		template <class U> bool	operator> (const reverse_iterator<U> &rhs) const { return this->_base.operator< (rhs.base()); };
		template <class U> bool	operator>=(const reverse_iterator<U> &rhs) const { return this->_base.operator<=(rhs.base()); };

}; // ************************************************** class ReverseIte end //

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void) : _base() { };

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator x) : _base(x) { };

template <class Iterator> template <class U>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<U> &u) : _base(u.base()) { };

template <class Iterator> template <class U>
reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator=(const reverse_iterator<U> &u) {
	if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&u))
		return (*this);
	this->_base = u.base();
	return (*this);
};

} // ******************************************************* ft namespace end //

#endif // ****************************************** REVERSEITE_CLASS_HPP end //
