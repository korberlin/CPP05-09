/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:26 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:47:27 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw "Form is not signed";
	if (executor.getGrade() > this->getExec())
		throw AForm::GradeTooLowException();
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw "File can not be opened";
	ofs << "         /\\         " << std::endl;
	ofs << "        /  \\        " << std::endl;
	ofs << "       /    \\       " << std::endl;
	ofs << "      /______\\      " << std::endl;
	ofs << "       /\\  /\\       " << std::endl;
	ofs << "      /  \\/  \\      " << std::endl;
	ofs << "     /        \\     " << std::endl;
	ofs << "    /__________\\    " << std::endl;
	ofs << "        ||||         " << std::endl;
	ofs << "        ||||         " << std::endl;
	ofs.close();
}
