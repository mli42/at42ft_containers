/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIte.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/02/08 14:10:36 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITE_CLASS_HPP
# define REVERSEITE_CLASS_HPP

# include "base.hpp"
# include "RandomIte.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator : public RandIte<typename Iterator::value_type> {
	protected:
		typedef RandIte<typename Iterator::value_type>	super;
		typedef Iterator								super_t;
		Iterator _base;
	public:
		typedef Iterator							iterator_type;
		typedef typename super_t::difference_type	difference_type;
		typedef typename super_t::reference			reference;
		typedef typename super_t::pointer			pointer;

		reverse_iterator(void);
		explicit reverse_iterator(Iterator x);
		template <class U> reverse_iterator(const reverse_iterator<U> &u);
		template <class U> reverse_iterator &operator=(const reverse_iterator<U> &u);
		Iterator base(void) const { return this->_base; };

		reference			operator*(void) const { return super_t::operator*(); };
		pointer				operator->(void) const { return super_t::operator->(); };

		reverse_iterator	&operator++(void) { super_t::operator--(); return *this; };
		reverse_iterator	operator++(int) { return super_t::operator--(0); };
		reverse_iterator	&operator--(void) { super_t::operator++(); return *this; };
		reverse_iterator	operator--(int) { return super_t::operator++(0); };

		template <class U>
		difference_type		operator-(const reverse_iterator<U> &u) { return super_t::operator-(u.base()); };
		reverse_iterator	operator+ (difference_type n) const { return super_t::operator-(n); };
		reverse_iterator	&operator+=(difference_type n) { return super_t::operator-=(n); };
		reverse_iterator	operator- (difference_type n) const { return super_t::operator+(n); };
		reverse_iterator	&operator-=(difference_type n) { return super_t::operator+=(n); };
		reference			operator[](difference_type n) const { return super_t::operator[](n); };

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs)
			{ return rhs.operator+(n); };

}; // ************************************************** class ReverseIte end //

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void) : _base() { };

} // ******************************************************* ft namespace end //

#endif // ****************************************** REVERSEITE_CLASS_HPP end //
