/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:18:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 09:18:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
    const std::string target;

public:
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};
