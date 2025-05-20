/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:52:35 by marvin            #+#    #+#             */
/*   Updated: 2025/05/16 15:52:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &n, int signGrade, int execGrade)
    : name(n), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade) {}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat &executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << ", signed: " << std::boolalpha << f.getIsSigned()
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
