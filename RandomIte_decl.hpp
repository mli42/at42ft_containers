/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIte_decl.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:56:40 by mli               #+#    #+#             */
/*   Updated: 2021/02/08 14:04:25 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMITE_DECL_CLASS_HPP
# define RANDOMITE_DECL_CLASS_HPP

# include "base.hpp"

namespace ft {

	template <typename Spe>
	class RandIte {
		protected:
		Spe									*_value;

		public:
		typedef Spe						value_type;
		typedef ptrdiff_t				difference_type;

		RandIte(void);
		RandIte(Spe *src);
		RandIte(const RandIte &src);
		virtual ~RandIte(void);
		RandIte	&operator=(RandIte const &rhs);

		bool	operator==(const RandIte &rhs) const;
		bool	operator!=(const RandIte &rhs) const;
		bool	operator<(const RandIte &rhs) const;
		bool	operator<=(const RandIte &rhs) const;
		bool	operator>(const RandIte &rhs) const;
		bool	operator>=(const RandIte &rhs) const;

		RandIte<Spe>	&operator++(void);
		RandIte<Spe>	operator++(int);
		RandIte<Spe>	&operator--(void);
		RandIte<Spe>	operator--(int);

		difference_type				operator-(const RandIte &rhs) const;
		RandIte<Spe>			operator+(difference_type n) const;
		RandIte<Spe>			operator-(difference_type n) const;
		friend RandIte<Spe>	operator+(difference_type n, const RandIte &rhs)
			{ return rhs.operator+(n); };

		/* Cannnot do reversed subtraction
		friend RandIte<Spe>	operator-(difference_type n, const RandIte &rhs)
			{ return (RandIte(rhs._value - n)); };
		*/

		/* Declared in sub-classes:
		reference	operator*(void) const;
		pointer		operator->(void) const;
		reference			operator+=(difference_type n);
		reference			operator-=(difference_type n);
		reference			operator[](difference_type n);
		*/

	}; // ************************************************* class RandIte end //

} // ******************************************************* ft namespace end //

#endif // ************************************** RANDOMITE_DECL_CLASS_HPP end //
