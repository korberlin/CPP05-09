/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:01 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:02 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _grade(150), _exec(150) {

}

Form::Form(const std::string& name, unsigned int grade, unsigned int exec)
	: _name(name), _signed(false), _grade(grade), _exec(exec) {
	if (grade < 1 || exec < 1)
		throw GradeTooHighException();
	if (grade > 150 || exec > 150)
		throw GradeTooLowException();
}

Form::~Form() {

}

Form::Form(const Form& other):
	_name(other._name), _signed(other._signed), _grade(other._grade), _exec(other._exec) {

}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

const std::string& Form::getName() const {
	return _name;
}

const bool& Form::getSigned() const {
	return _signed;
}

unsigned int Form::getGrade() const {
	return _grade;
}


unsigned int Form::getExec() const {
	return _exec;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade Too High (Form)";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& other) {
	os << other.getName() << " form grade " << other.getGrade() << " required grade to execute is " << other.getExec() << ". \nSigned: " << other.getSigned();
	return os;
}
