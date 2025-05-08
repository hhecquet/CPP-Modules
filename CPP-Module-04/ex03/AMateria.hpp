/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:55:24 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/08 15:05:33 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria& operator=(AMateria const & rhs);
		virtual ~AMateria();//{} ?
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif