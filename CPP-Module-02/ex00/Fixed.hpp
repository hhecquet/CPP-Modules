/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:06 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/30 11:08:20 by hhecquet         ###   ########.fr       */
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
		Fixed(void);//Un constructeur par défaut qui initialisera la valeur du nombre à virgule fixe à 0.
		Fixed(const Fixed& other);//Un constructeur de recopie.
		Fixed& operator=(const Fixed& other);//Une surcharge de l’opérateur d’affectation. //other ?
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif