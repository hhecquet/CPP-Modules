/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:05:16 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 10:05:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &target);

private:
    static AForm* createShrubbery(const std::string &target);
    static AForm* createRobotomy(const std::string &target);
    static AForm* createPresidential(const std::string &target);
};