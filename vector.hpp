/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/10/31 21:38:52 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

# include "base.hpp"

namespace ft {

template< typename T, typename Alloc = std::allocator<T> >
class vector {
	public:

		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		// Member functions

		vector(void);
		vector(vector const &src);
		virtual ~vector(void);

		vector	&operator=(vector const &rhs);

		// Iterators

		// Capacity

		size_type	size(void) const;
		size_type	capacity(void) const;
		size_type	max_size(void) const;

		// Element access
		// Modifiers
		// Allocator

	protected:
	private:
		T						*_data;
		size_type				_size;
		size_type				_capacity;
		const static size_type	_max_size;
};

template<typename T, typename Alloc>
vector<T, Alloc>::vector(void) : _data(NULL), _size(0), _capacity(0) {
	return ;
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector const &src) {
	*this = src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::~vector(void) {
	return ;
}

template<typename T, typename Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator=(vector const &rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size(void) const {
	return (this->_size);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity(void) const {
	return (this->_capacity);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size(void) const {
	return (_max_size);
}

template <typename T, typename Alloc>
const typename vector<T, Alloc>::size_type vector<T, Alloc>::_max_size =
	std::numeric_limits<difference_type>::max() / (sizeof(T) / 2 ?: 1);

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
