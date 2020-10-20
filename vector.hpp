/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:55:50 by mli               #+#    #+#             */
/*   Updated: 2020/10/20 16:58:52 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

# include "base.hpp"

namespace ft {

template<typename T>
class vector {
	public:
		vector(void);
		vector(vector const &src);
		virtual ~vector(void);

		vector	&operator=(vector const &rhs);

	protected:
	private:
};

template<typename T>
vector<T>::vector(void) {
	return ;
}

template<typename T>
vector<T>::vector(vector const &src) {
	*this = src;
}

template<typename T>
vector<T>::~vector(void) {
	return ;
}

template<typename T>
vector<T>	&vector<T>::operator=(vector const &rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

} // ******************************************************* ft namespace end //

#endif // ********************************************** VECTOR_CLASS_HPP end //
