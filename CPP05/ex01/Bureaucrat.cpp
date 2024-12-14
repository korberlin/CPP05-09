/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:56 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:45:57 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {

}

Bureaucrat::Bureaucrat(const std::string& name): _name(name), _grade(150) {

}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {

}

unsigned int Bureaucrat::getGrade(void) const {
	return _grade;
}

const std::string& Bureaucrat::getName(void) const {
	return _name;
}

void Bureaucrat::increment() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::signForm(Form& other) {
	try {
		other.beSigned(*this);
		std::cout << _name << " signed " << other.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << _name << " couldn't sign " << other.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::decrement() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other) {
	os << other.getName() << " bureaucrat grade " << other.getGrade();
	return os;
}
