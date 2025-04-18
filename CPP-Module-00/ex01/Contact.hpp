/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact,hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:12:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 07:12:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact{
	private:
		std::string phone_number;
		std::string darkest_secret;
		std::string first_name;
		std::string last_name;
		std::string nickname;
	public:
		Contact(void);
		~Contact(void);
		std::string	get_first(void) const;
		std::string	get_last(void) const;
		std::string	get_nick(void) const;
		std::string	get_number(void) const;
		std::string	get_secret(void) const;
		void		set_first(std::string str);
		void		set_last(std::string str);
		void		set_nick(std::string str);
		void		set_number(std::string str);
		void		set_secret(std::string str);
};

#endif