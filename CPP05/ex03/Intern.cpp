/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:11 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:47:12 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {

}

AForm* Intern::createShrubberyCreation(std::string target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardon(std::string target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequest(std::string target) const {
	return new RobotomyRequestForm(target);
}


AForm* Intern::makeForm(std::string name, std::string target) {
	static AForm *(Intern::*membFunc[3])(std::string) const = {
		&Intern::createShrubberyCreation,
		&Intern::createPresidentialPardon,
		&Intern::createRobotomyRequest,
	};
	std::string forms[3] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};
	for (int i = 0; i < 3; i++) {
		if (name == forms[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*membFunc[i])(target);
		}
	}
	throw "Form does not exist";
}
