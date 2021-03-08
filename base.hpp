/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:57:26 by mli               #+#    #+#             */
/*   Updated: 2021/03/08 23:31:38 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

# include <iostream>
# include <string>
# include <memory>
# include <limits>
# include <cstddef> // ptrdiff_t
# include <sstream> // ostring

namespace ft {

// struct choose<bool, true, false>

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

// struct enable_if<bool, true>

template <bool, class IsTrue = void>
struct enable_if;

template <class IsTrue>
struct enable_if<true, IsTrue> {
	typedef IsTrue type;
};

// Relational Operators Comparison Functions

template <class Ite1, class Ite2>
bool	equal(Ite1 first1, Ite1 last1, Ite2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return false;
		++first1; ++first2;
	}
	return true;
}

// Ite len

template <class Ite>
size_t	itlen(Ite first, Ite last) {
	size_t	i = 0;

	while (first != last)
	{
		++first;
		++i;
	}
	return (i);
}

// true if the first range compares lexicographically less than the second.
// false otherwise (including when all the elements of both ranges are equivalent).

template <class Ite1, class Ite2>
bool	lexicographical_compare(Ite1 first1, Ite1 last1, Ite2 first2, Ite2 last2)
{
	while (first1 != last1 && first2 != last2 && *first1 == *first2)
	{
		++first1; ++first2;
	}
	if (first1 == last1)
		return (first2 != last2);
	else if (first2 == last2)
		return (false);
	return (*first1 < *first2);
}

template <typename T>
struct	lstNode
{
	T			data;
	lstNode		*next;
	lstNode		*prev;

	lstNode(const T &src = T()) : data(src), next(this), prev(this) {};
};

template <typename T>
struct	mapNode
{
	private:
	bool _unused;
	#if __APPLE__ == 0
		int _unused_for_linux;
	#endif

	public:
	T			data;
	mapNode		*parent;
	mapNode		*left;
	mapNode		*right;

	mapNode(const T &src = T()) : \
		data(src), parent(NULL), left(NULL), right(NULL) {};
};

template <typename T>
mapNode<T>	*farRight(mapNode<T> *node) {
	while (node->right != NULL)
		node = node->right;
	return (node);
}

template <typename T>
mapNode<T>	*farLeft(mapNode<T> *node) {
	while (node->left != NULL)
		node = node->left;
	return (node);
}

// pair struct for ft::map

template <class T1, class T2>
struct	pair
{
	typedef T1		first_type;
	typedef T2		second_type;

	first_type		first;
	second_type		second;

	// Member functions

	pair(void) : first(), second() { };
	template<class U, class V>
	pair(const pair<U, V> &src) : first(src.first), second(src.second) { };
	pair(const first_type &a, const second_type &b) : first(a), second(b) { };

	pair	&operator=(const pair &src) {
		if (this == &src)
			return (*this);
		this->first = src.first;
		this->second = src.second;
		return (*this);
	}
};

template <class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return !(lhs == rhs);
}

template <class T1, class T2>
bool operator< (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return !(rhs < lhs);
}

template <class T1, class T2>
bool operator> (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return !(lhs < rhs);
}


} // ******************************************************* ft namespace end //

#endif // ************************************************ BASE_CLASS_HPP end //
