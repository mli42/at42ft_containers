/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_decl.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:53:53 by mli               #+#    #+#             */
/*   Updated: 2021/02/19 10:26:20 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DECL_CLASS_HPP
# define LIST_DECL_CLASS_HPP

# include "base.hpp"
# include "lstIte.hpp"
# include "ReverseIte.hpp"

namespace ft {

template< typename T, typename Alloc = std::allocator<T> >
class list {
	public:
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

	typedef ft::lstIte<value_type>					iterator;
	typedef ft::lstIte<const value_type>			const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

// ************************** Member functions ****************************** //

	explicit list(const allocator_type &alloc = allocator_type());
	explicit list(size_type size, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type());
	template <class Ite>
	list(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
			Ite last, const allocator_type &alloc = allocator_type());
	list(const list &src);
	virtual ~list(void);

	list	&operator=(list const &rhs);

// ****************************** Iterators ********************************* //

	iterator		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;

	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;

// ******************************* Capacity ********************************* //

	size_type	size(void) const;
	size_type	max_size(void) const;
	bool		empty(void) const;

// ******************************* Ele Access ******************************* //

	reference			front(void);
	const_reference		front(void) const;
	reference			back(void);
	const_reference		back(void) const;

// ******************************** Modifiers ******************************* //

	template <class Ite>
	void		assign(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first, Ite last);
	void		assign(size_type n, const value_type &val);
	void		push_front(const value_type &val);
	void		pop_front(void);
	void		push_back(const value_type &val);
	void		pop_back(void);

	iterator	insert(iterator position, const value_type &val);
	void		insert(iterator position, size_type n, const value_type &val);
	template <class Ite>
	void	insert(iterator position, Ite first,
		typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type last);

	iterator	erase(iterator ite);
	iterator	erase(iterator first, iterator last);
	void		swap(list &x);
	void		clear(void);
	void		resize(size_type n, const value_type &val = value_type());

	protected:
	private:
	lstNode<value_type>		_data;
	allocator_type			_alloc;
	size_type				_size;
	const static size_type	_max_size;

}; // **************************************************** class ft::list end //

} // ******************************************************* ft namespace end //

#endif // ******************************************* LIST_DECL_CLASS_HPP end //
