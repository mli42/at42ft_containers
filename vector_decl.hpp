/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_decl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:46:13 by mli               #+#    #+#             */
/*   Updated: 2021/01/06 14:58:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_DECL_CLASS_HPP
# define VECTOR_DECL_CLASS_HPP

# include "base.hpp"

namespace ft {

template <bool flag, class IsTrue, class IsFalse>
struct choose;

template <class IsTrue, class IsFalse>
struct choose<true, IsTrue, IsFalse> {
	typedef IsTrue type;
};

template <class IsTrue, class IsFalse>
struct choose<false, IsTrue, IsFalse> {
	typedef IsFalse type;
};

template< typename T, typename Alloc = std::allocator<T> >
class vector {
	public:

	template <typename Spe, bool is_const>
	class VectIte;

	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef VectIte<value_type, false>					iterator;
	typedef VectIte<value_type, true>					const_iterator;

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
	void		reserve(size_type n);

	// Element access

	// Modifiers
	void		push_back(const value_type &val);
	void		pop_back(void);
	iterator	erase(iterator ite);
	iterator	erase(iterator first, iterator last);

	protected:
	private:
	value_type				*_data;
	allocator_type			_alloc;
	size_type				_size;
	size_type				_capacity;
	const static size_type	_max_size;

	template <class Ite>
	void				_create_data(difference_type capacity, Ite first, Ite last);
	void				_create_data(size_type size, const value_type &val = value_type());
	static void			_destroy_data(vector &vct);
	template <class Ite, class Iterator>
	static void			_cpy_data(Ite start, Iterator first, Iterator last);
	void				_cpy_content(vector &vct);

	// ########################## Iterators ####################################

	public:

	template <typename Spe, bool is_const>
	class VectIte {
		public:
	//	typedef Spe													value_type;
		typedef difference_type										difference_type;
		typedef typename choose<is_const, const Spe, Spe>::type&	reference;
		typedef typename choose<is_const, const Spe, Spe>::type*	pointer;

		VectIte(void);
		VectIte(Spe *src);
		VectIte(const VectIte &src);
		VectIte(const VectIte<Spe, !is_const> &src);
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

		VectIte<Spe, is_const>	&operator++(void);
		VectIte<Spe, is_const>	operator++(int);
		VectIte<Spe, is_const>	&operator--(void);
		VectIte<Spe, is_const>	operator--(int);

		VectIte<Spe, is_const>		operator+(difference_type n);
		friend VectIte<Spe, is_const>	operator+(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs->_value + n)); };

		VectIte<Spe, is_const>		operator-(difference_type n);
		friend VectIte<Spe, is_const>	operator-(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs->_value - n)); };

		difference_type		operator-(const VectIte &rhs);
		reference			operator+=(difference_type n);
		reference			operator-=(difference_type n);
		reference			operator[](difference_type n);

		protected:
		Spe				*_value;
	}; // ************************************************* class VectIte end //

}; // ************************************************** class ft::vector end //

} // ******************************************************* ft namespace end //

#endif // ***************************************** VECTOR_DECL_CLASS_HPP end //
