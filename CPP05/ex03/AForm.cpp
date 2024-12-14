/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:55 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:56 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _grade(150), _exec(150) {

}

AForm::AForm(const std::string& name, unsigned int grade, unsigned int exec)
	: _name(name), _signed(false), _grade(grade), _exec(exec) {
	if (grade < 1 || exec < 1)
		throw GradeTooHighException();
	if (grade > 150 || exec > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {

}

AForm::AForm(const AForm& other):
	_name(other._name), _signed(other._signed), _grade(other._grade), _exec(other._exec) {

}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

const std::string& AForm::getName() const {
	return _name;
}

const bool& AForm::getSigned() const {
	return _signed;
}

unsigned int AForm::getGrade() const {
	return _grade;
}


unsigned int AForm::getExec() const {
	return _exec;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade Too High (Form)";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& other) {
	os << other.getName() << " form grade " << other.getGrade() << " required grade to execute is " << other.getExec() << ". \nSigned: " << other.getSigned();
	return os;
}
