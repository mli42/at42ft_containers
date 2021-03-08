/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:07:52 by mli               #+#    #+#             */
/*   Updated: 2021/03/08 12:25:15 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_DECL_CLASS_HPP
# define QUEUE_DECL_CLASS_HPP

# include "base.hpp"
# include "list.hpp"

namespace ft {

template <class T, class Container = ft::list<T> >
class queue {
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

	queue(const queue &src) : c(src.c) {};
	queue	&operator=(queue const &rhs) { this->c = rhs.c; };

	public:

// ************************** Member functions ****************************** //

	explicit queue(const container_type &ctnr = container_type()) : c(ctnr) {};
	virtual ~queue(void) {};

	size_type	size(void) const { return c.size(); };
	bool		empty(void) const { return c.empty(); };

	reference			front(void) { return c.front(); };
	const_reference		front(void) const { return c.front(); };

	reference			back(void) { return c.back(); };
	const_reference		back(void) const { return c.back(); };

	void				push(const value_type &val) { c.push_back(val); };
	void 				pop(void) { c.pop_front(); };

	friend
	bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs.c == rhs.c);
	}

	friend
	bool operator< (const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs.c < rhs.c);
	}

}; // *************************************************** class ft::queue end //

template <class T, class Container>
bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Container>
bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Container>
bool operator> (const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
	return !(lhs < rhs);
}

} // ******************************************************* ft namespace end //

#endif // ****************************************** QUEUE_DECL_CLASS_HPP end //
