/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIte_decl.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/01/09 23:12:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMITE_DECL_CLASS_HPP
# define RANDOMITE_DECL_CLASS_HPP

# include "base.hpp"

namespace ft {

	template <typename Spe, bool is_const>
	class VectIte {
		protected:
		typedef Spe						value_type;
		value_type						*_value;

		public:
		typedef ptrdiff_t														difference_type;
		typedef typename choose<is_const, const value_type, value_type>::type&	reference;
		typedef typename choose<is_const, const value_type, value_type>::type*	pointer;

		VectIte(void);
		VectIte(value_type *src);
		VectIte(const VectIte &src);
		//VectIte(const VectIte<value_type, !is_const> &src);
		virtual ~VectIte(void);
		VectIte	&operator=(VectIte const &rhs);

		bool	operator==(const VectIte &rhs) const;
		bool	operator!=(const VectIte &rhs) const;
		bool	operator<(const VectIte &rhs) const;
		bool	operator<=(const VectIte &rhs) const;
		bool	operator>(const VectIte &rhs) const;
		bool	operator>=(const VectIte &rhs) const;

		reference	operator*(void) const;
		pointer		operator->(void) const;

		VectIte<value_type, is_const>	&operator++(void);
		VectIte<value_type, is_const>	operator++(int);
		VectIte<value_type, is_const>	&operator--(void);
		VectIte<value_type, is_const>	operator--(int);

		VectIte<value_type, is_const>			operator+(difference_type n);
		VectIte<value_type, is_const>			operator-(difference_type n);
		friend VectIte<value_type, is_const>	operator+(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs._value + n)); };

		/* Cannnot do reversed subtraction
		friend VectIte<value_type, is_const>	operator-(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs._value - n)); };
		*/

		difference_type		operator-(const VectIte &rhs);
		reference			operator+=(difference_type n);
		reference			operator-=(difference_type n);
		reference			operator[](difference_type n);
	}; // ************************************************* class VectIte end //

} // ******************************************************* ft namespace end //

#endif // ************************************** RANDOMITE_DECL_CLASS_HPP end //
