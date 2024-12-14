/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:18 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:19 by gkoksal          ###   ########.fr       */
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

void Bureaucrat::signForm(AForm& other) {
	if (_grade <= other.getGrade()){
		other.beSigned(*this);
		std::cout << _name << " signed " << other.getName() << std::endl;
	}
	else {
		std::cout << _name << " couldn't sign " << other.getName() << " because the grade is too low" << std::endl;
	}
}

void Bureaucrat::decrement() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::executeForm(const AForm& form) {
	if (!form.getSigned()) {
		std::cout << _name << " couldn't execute the " << form.getName() << " because form is not signed" << std::endl;
		return ;
	}
	if (_grade > form.getExec())
		std::cout << _name << " couldn't execute the " << form.getName() << "because the grade is too low" << std::endl;
	else {
		std::cout << _name << " executed the " << form.getName() << std::endl;
		form.execute(*this);
	}
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
