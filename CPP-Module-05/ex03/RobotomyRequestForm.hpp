/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:18:34 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 09:18:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
    const std::string target;

public:
    RobotomyRequestForm(const std::string &target);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;
};