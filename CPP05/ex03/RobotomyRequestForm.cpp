/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:23 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:47:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		_target = other._target;
		AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw "Form is not signed";
	if (executor.getGrade() > this->getExec())
		throw AForm::GradeTooLowException();
	std::cout<< "bzzzz Drilling has begun bzzz ..." << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been successfully robotomized" << std::endl;
	else
		std::cout << _target << " can not be robotomized" << std::endl;
}
