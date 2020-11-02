/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_decl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:46:13 by mli               #+#    #+#             */
/*   Updated: 2020/11/02 20:45:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_DECL_CLASS_HPP
# define VECTOR_DECL_CLASS_HPP

# include "base.hpp"

namespace ft {

template< typename T, typename Alloc = std::allocator<T> >
class vector {
	public:

	template <typename Spe>
	class VectIte;

	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef VectIte<value_type>							iterator;
	typedef VectIte<const value_type>					const_iterator;

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

	protected:
	private:
	value_type				*_data;
	allocator_type			_alloc;
	size_type				_size;
	size_type				_capacity;
	const static size_type	_max_size;

	// ########################## Iterators ####################################

	public:

	template <typename Spe>
	class VectIte {
		public:
	//	typedef Spe			value_type;
		typedef Spe*		pointer;
		typedef Spe&		reference;

		VectIte(void);
		VectIte(const VectIte &src);
		~VectIte(void);
		VectIte	&operator=(VectIte const &rhs);

		bool	operator==(const VectIte &rhs) const;
		bool	operator!=(const VectIte &rhs) const;
		bool	operator<(const VectIte &rhs) const;
		bool	operator<=(const VectIte &rhs) const;
		bool	operator>(const VectIte &rhs) const;
		bool	operator>=(const VectIte &rhs) const;

		reference	operator*(void) const;
		pointer		operator->(void) const;

		protected:
		pointer				_value;
	}; // ************************************************* class VectIte end //

}; // ************************************************** class ft::vector end //

} // ******************************************************* ft namespace end //

#endif // ***************************************** VECTOR_DECL_CLASS_HPP end //
