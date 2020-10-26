/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/10/26 17:06:11 by mli              ###   ########.fr       */
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

		vector(void);
		vector(vector const &src);
		virtual ~vector(void);

		vector	&operator=(vector const &rhs);

	protected:
	private:
};

template<typename T, typename Alloc>
vector<T, Alloc>::vector(void) {
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

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
