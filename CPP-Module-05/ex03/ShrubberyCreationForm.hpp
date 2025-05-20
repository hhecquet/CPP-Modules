/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:18:40 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 09:18:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    const std::string target;

public:
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
};