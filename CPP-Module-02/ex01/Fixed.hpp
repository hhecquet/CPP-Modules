/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:06 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/30 13:03:27 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <string>

class Fixed
{
	private :
		int _rawBits;
		static const int _bits = 8;
	public :
		Fixed();
		Fixed(const int n);//Un constructeur prenant un entier constant en paramètre et qui convertit celui-ci en virgule fixe.
		Fixed(const float f);//Un constructeur prenant un flottant constant en paramètre et qui convertit celui-ci en virgule fixe.
		Fixed& operator<<(const Fixed& other);//Une surcharge de l’opérateur d’insertion.
		~Fixed(void);
		float toFloat( void ) const;
		int toInt( void ) const;
};

#endif