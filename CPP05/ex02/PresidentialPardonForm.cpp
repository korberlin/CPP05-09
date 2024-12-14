/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:37 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:38 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other) {
	_target = other._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		_target = other._target;
		AForm::operator=(other);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw "Form is not signed";
	if (executor.getGrade() > getExec())
		throw AForm::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
