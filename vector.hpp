/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/11/01 23:00:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

# include "base.hpp"
# include "vector_decl.hpp"

namespace ft {

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
