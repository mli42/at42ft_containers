/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:53:34 by mli               #+#    #+#             */
/*   Updated: 2021/03/08 12:25:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_DECL_CLASS_HPP
# define STACK_DECL_CLASS_HPP

# include "base.hpp"
# include "list.hpp"

namespace ft {

template <class T, class Container = ft::list<T> >
class stack {
	public:
	typedef T						value_type;
	typedef Container				container_type;
	typedef size_t					size_type;

	protected:
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef value_type*				pointer;
	typedef const value_type*		const_pointer;

	container_type	c;

	stack(const stack &src) : c(src.c) {};
	stack	&operator=(stack const &rhs) { this->c = rhs.c; };

	public:

// ************************** Member functions ****************************** //

	explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {};
	virtual ~stack(void) {};

	size_type	size(void) const { return c.size(); };
	bool		empty(void) const { return c.empty(); };

	reference			top(void) { return c.back(); };
	const_reference		top(void) const { return c.back(); };
	void				push(const value_type &val) { c.push_back(val); };
	void 				pop(void) { c.pop_back(); };

	friend
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c == rhs.c);
	}

	friend
	bool operator< (const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c < rhs.c);
	}

}; // *************************************************** class ft::stack end //

template <class T, class Container>
bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Container>
bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Container>
bool operator> (const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
	return !(lhs < rhs);
}

} // ******************************************************* ft namespace end //

#endif // ****************************************** STACK_DECL_CLASS_HPP end //
