/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_decl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:46:13 by mli               #+#    #+#             */
/*   Updated: 2020/11/05 21:53:41 by mli              ###   ########.fr       */
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
	explicit vector(size_type size, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type());
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		const allocator_type &alloc = allocator_type());
	vector(const vector &src);
	virtual ~vector(void);

	vector	&operator=(vector const &rhs);

	// Iterators
	iterator		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;
	// Capacity

	size_type	size(void) const;
	size_type	capacity(void) const;
	size_type	max_size(void) const;
	void		resize(size_type size, value_type val = value_type());

	// Element access

	// Modifiers
	iterator	erase(iterator ite);
	iterator	erase(iterator first, iterator last);

	protected:
	private:
	value_type				*_data;
	allocator_type			_alloc;
	size_type				_size;
	size_type				_capacity;
	const static size_type	_max_size;

	void					_create_data(size_type size, value_type val);
	void					_destroy_data(void);
	template <class InputIterator>
	void					_cpy_data(InputIterator first, InputIterator last);

	// ########################## Iterators ####################################

	public:

	template <typename Spe>
	class VectIte {
		public:
	//	typedef Spe				value_type;
		typedef difference_type	difference_type;
		typedef Spe*			pointer;
		typedef Spe&			reference;

		VectIte(void);
		VectIte(const pointer &src);
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

		VectIte<Spe>	&operator++(void);
		VectIte<Spe>	operator++(int);
		VectIte<Spe>	&operator--(void);
		VectIte<Spe>	operator--(int);

		VectIte<Spe>		operator+(difference_type n);
		friend VectIte<Spe>	operator+(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs->_value + n)); };

		VectIte<Spe>		operator-(difference_type n);
		friend VectIte<Spe>	operator-(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs->_value - n)); };

		difference_type		operator-(const VectIte &rhs);
		reference			operator+=(difference_type n);
		reference			operator-=(difference_type n);
		reference			operator[](difference_type n);

		protected:
		pointer				_value;
	}; // ************************************************* class VectIte end //

}; // ************************************************** class ft::vector end //

} // ******************************************************* ft namespace end //

#endif // ***************************************** VECTOR_DECL_CLASS_HPP end //
