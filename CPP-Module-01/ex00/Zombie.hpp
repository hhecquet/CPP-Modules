/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:02:06 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/22 10:39:53 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif