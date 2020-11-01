/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/11/01 18:34:14 by mli              ###   ########.fr       */
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

	explicit vector(const allocator_type &alloc = allocator_type());
	explicit vector(size_type n, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type());
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		const allocator_type &alloc = allocator_type());
	vector(const vector &src);
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
	value_type				*_data;
	allocator_type			_alloc;
	size_type				_size;
	size_type				_capacity;
	const static size_type	_max_size;
};

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type &alloc) : \
	_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
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
