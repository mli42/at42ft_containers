/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_decl.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:46:13 by mli               #+#    #+#             */
/*   Updated: 2021/02/18 21:58:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_DECL_CLASS_HPP
# define VECTOR_DECL_CLASS_HPP

# include "base.hpp"
# include "RandomIte.hpp"
# include "ReverseIte.hpp"

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

	class iterator : public RandIte<value_type> {
		protected:
		typedef RandIte<value_type> super;
		iterator(value_type *src) : RandIte<value_type>(src) {};
		private:
		iterator(const RandIte<value_type> &src) : RandIte<value_type>(src) {};

		public:
		iterator(void) : RandIte<value_type>() {};
		iterator(const iterator &src) : RandIte<value_type>(src) {};

		typedef value_type&			reference;
		typedef value_type*			pointer;

		reference			operator*(void) const;
		pointer				operator->(void) const;
		iterator			&operator+=(difference_type n);
		iterator			&operator-=(difference_type n);
		reference			operator[](difference_type n) const;

		difference_type		operator-(const RandIte<value_type> &n) const { return super::operator-(n); };
		iterator			operator-(difference_type n) const { return super::operator-(n); };
		iterator			operator+(difference_type n) const { return super::operator+(n); };
		friend iterator		operator+(difference_type n, const iterator &rhs) { return rhs.operator+(n); };

		iterator			&operator++(void) { super::operator++(); return *this; };
		iterator			operator++(int) { return super::operator++(0); };
		iterator			&operator--(void) { super::operator--(); return *this; };
		iterator			operator--(int) { return super::operator--(0); };

		friend class vector;
	};
	class const_iterator : public RandIte<value_type> {
		protected:
		typedef RandIte<value_type> super;
		const_iterator(value_type *src) : RandIte<value_type>(src) {};
		public:
		const_iterator(void) : RandIte<value_type>() {};
		const_iterator(const RandIte<value_type> &src) : RandIte<value_type>(src) {};

		typedef const value_type&		reference;
		typedef const value_type*		pointer;

		reference			operator*(void) const;
		pointer				operator->(void) const;
		const_iterator		&operator+=(difference_type n);
		const_iterator		&operator-=(difference_type n);
		reference			operator[](difference_type n) const;

		difference_type		operator-(const RandIte<value_type> &n) const { return super::operator-(n); };
		const_iterator		operator-(difference_type n) const { return super::operator-(n); };
		const_iterator		operator+(difference_type n) const { return super::operator+(n); };
		friend const_iterator	operator+(difference_type n, const const_iterator &rhs) { return rhs.operator+(n); };

		const_iterator		&operator++(void) { super::operator++(); return *this; };
		const_iterator		operator++(int) { return super::operator++(0); };
		const_iterator		&operator--(void) { super::operator--(); return *this; };
		const_iterator		operator--(int) { return super::operator--(0); };

		friend class vector;
	};
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	// Member functions

	explicit vector(const allocator_type &alloc = allocator_type());
	explicit vector(size_type size, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type());
	template <class Ite>
	vector(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
			Ite last, const allocator_type &alloc = allocator_type());
	vector(const vector &src);
	virtual ~vector(void);

	vector	&operator=(vector const &rhs);

	// Iterators
	iterator		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;

	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;

	// Capacity
	size_type	size(void) const;
	size_type	capacity(void) const;
	size_type	max_size(void) const;
	void		resize(size_type size, value_type val = value_type());
	bool		empty(void) const;
	void		reserve(size_type n);

	// Element access
	reference			operator[](size_type n);
	const_reference		operator[](size_type n) const;
	reference			at(size_type n);
	const_reference		at(size_type n) const;
	reference			front(void);
	const_reference		front(void) const;
	reference			back(void);
	const_reference		back(void) const;

	// Modifiers
	template <class Ite>
	void		assign(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first, Ite last);
	void		assign(size_type n, const value_type &val);
	void		push_back(const value_type &val);
	void		pop_back(void);

	iterator	insert(iterator position, const value_type &val);
	void		insert(iterator position, size_type n, const value_type &val);
	template <class Ite>
		void	insert(iterator position, Ite first,
			typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type last);

	iterator	erase(iterator ite);
	iterator	erase(iterator first, iterator last);
	void		swap(vector &x);
	void		clear(void);

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
	void				_destroy_data(void);
	template <class Ite, class Iterator>
	static void			_cpy_data(Ite start, Iterator first, Iterator last);
	void				_cpy_content(vector &vct);

}; // ************************************************** class ft::vector end //

} // ******************************************************* ft namespace end //

#endif // ***************************************** VECTOR_DECL_CLASS_HPP end //
