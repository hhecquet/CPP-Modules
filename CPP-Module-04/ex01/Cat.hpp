/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:14:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 14:46:04 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
        Brain* brain;
    public:
        Cat(void);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat(void);

        void makeSound(void) const;
		void setIdeas(const std::string& idea, int index);
		std::string getIdeas(int index) const;
};

#endif