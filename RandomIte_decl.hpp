/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIte_decl.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/01/11 12:07:15 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMITE_DECL_CLASS_HPP
# define RANDOMITE_DECL_CLASS_HPP

# include "base.hpp"

namespace ft {

	template <typename Spe>
	class VectIte {
		protected:
		//typedef Spe						value_type;
		Spe									*_value;

		public:
		typedef ptrdiff_t				difference_type;

		VectIte(void);
		VectIte(Spe *src);
		VectIte(const VectIte &src);
		virtual ~VectIte(void);
		VectIte	&operator=(VectIte const &rhs);

		bool	operator==(const VectIte &rhs) const;
		bool	operator!=(const VectIte &rhs) const;
		bool	operator<(const VectIte &rhs) const;
		bool	operator<=(const VectIte &rhs) const;
		bool	operator>(const VectIte &rhs) const;
		bool	operator>=(const VectIte &rhs) const;

		VectIte<Spe>	&operator++(void);
		VectIte<Spe>	operator++(int);
		VectIte<Spe>	&operator--(void);
		VectIte<Spe>	operator--(int);

		difference_type				operator-(const VectIte &rhs);
		VectIte<Spe>			operator+(difference_type n);
		VectIte<Spe>			operator-(difference_type n);
		friend VectIte<Spe>	operator+(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs._value + n)); };

		/* Cannnot do reversed subtraction
		friend VectIte<Spe>	operator-(difference_type n, const VectIte &rhs)
			{ return (VectIte(rhs._value - n)); };
		*/

		/* Declared in sub-classes:
		reference	operator*(void) const;
		pointer		operator->(void) const;
		reference			operator+=(difference_type n);
		reference			operator-=(difference_type n);
		reference			operator[](difference_type n);
		*/

	}; // ************************************************* class VectIte end //

} // ******************************************************* ft namespace end //

#endif // ************************************** RANDOMITE_DECL_CLASS_HPP end //
