/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:57:26 by mli               #+#    #+#             */
/*   Updated: 2021/01/22 10:50:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# include <iostream>
# include <string>
# include <memory>
# include <limits>

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

} // ******************************************************* ft namespace end //

#endif // ************************************************ BASE_CLASS_HPP end //
