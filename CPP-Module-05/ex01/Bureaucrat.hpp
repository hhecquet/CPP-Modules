/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:16:45 by marvin            #+#    #+#             */
/*   Updated: 2025/05/16 14:16:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
    private:
    	const std::string name;
    	int grade;

    public:
    	Bureaucrat();
    	Bureaucrat(const std::string &name, int grade);
    	Bureaucrat(const Bureaucrat &other);
    	Bureaucrat &operator=(const Bureaucrat &other);
    	~Bureaucrat();

		void signForm(Form &form);

    	const std::string &getName() const;
    	int getGrade() const;

    	void incrementGrade();
    	void decrementGrade();

    	class GradeTooHighException : public std::exception 
        {
        	public:
        		const char *what() const throw();
    	};

    	class GradeTooLowException : public std::exception
        {
    	    public:
    		    const char *what() const throw();
    	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
