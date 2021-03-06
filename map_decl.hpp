/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_decl.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:56:50 by mli               #+#    #+#             */
/*   Updated: 2021/03/06 12:37:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DECL_CLASS_HPP
# define MAP_DECL_CLASS_HPP

# include "base.hpp"
# include "mapIte.hpp"
# include "ReverseIte.hpp"

namespace ft {

template < class Key,                                     // map::key_type
		 class T,                                         // map::mapped_type
		 class Compare = std::less<Key>,                  // map::key_compare
		 class Alloc = std::allocator<pair<const Key,T> > // map::allocator_type
		 >
class map {
	public:

	typedef Key											key_type;
	typedef T											mapped_type;
	typedef pair<const key_type, mapped_type>			value_type;
	typedef Compare										key_compare;
	class												value_compare;

	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef ft::mapNode<value_type>						node_type;
	typedef node_type*									node_ptr;

	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

	typedef ft::mapIte<value_type, node_type>			iterator;
	typedef ft::mapIte<const value_type, node_type>		const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

// ************************** Member functions ****************************** //

	explicit map(const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
	template <class Ite>
	map(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
			Ite last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
	map(const map &src);
	virtual ~map(void);

	map	&operator=(map const &rhs);

// ****************************** Iterators ********************************* //

	iterator				begin(void);
	const_iterator			begin(void) const;
	iterator				end(void);
	const_iterator			end(void) const;

	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;

// ******************************* Capacity ********************************* //

	size_type	size(void) const;
	size_type	max_size(void) const;
	bool		empty(void) const;

// ******************************* Ele Access ******************************* //

	mapped_type	&operator[](const key_type &k);

// ******************************** Modifiers ******************************* //

	ft::pair<iterator, bool>	insert(const value_type &val);
	iterator					insert(iterator position, const value_type &val);
	template <class Ite> void	insert(Ite first, Ite last);

	void		erase(iterator position);
	size_type	erase(const key_type &k);
	void		erase(iterator first, iterator last);

	void		swap(map &x);
	void		clear(void);

// ******************************* Observers ******************************** //

	key_compare		key_comp(void) const;
	value_compare	value_comp(void) const;

// ******************************* Operations ******************************* //

	iterator		find(const key_type &k);
	const_iterator	find(const key_type &k) const;
	size_type		count(const key_type &k) const;

	iterator		lower_bound(const key_type &k);
	const_iterator	lower_bound(const key_type &k) const;
	iterator		upper_bound(const key_type &k);
	const_iterator	upper_bound(const key_type &k) const;
	pair<const_iterator,const_iterator>	equal_range(const key_type &k) const;
	pair<iterator,iterator>				equal_range(const key_type &k);

// ******************************* Non-public ******************************* //

	protected:
	private:
	node_ptr				_data;
	key_compare				_key_cmp;
	allocator_type			_alloc;
	size_type				_size;
	const static size_type	_max_size;

	template <class Ite>
	void				_create_data_it(Ite first, Ite last);
	void				_create_data(size_type size, const value_type &val = value_type());
	void				_cpy_content(map &src);

	void				_btree_clear(node_ptr node);
	void				_btree_add(node_ptr node);
	void				_btree_rm(node_ptr node);

	bool				_key_eq(const key_type &k1, const key_type &k2) const;

}; // ***************************************************** class ft::map end //

} // ******************************************************* ft namespace end //

#endif // ******************************************** MAP_DECL_CLASS_HPP end //
