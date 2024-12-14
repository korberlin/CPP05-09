/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:59 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:47:00 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _grade;
		const unsigned int _exec;
		AForm();
	public:
		AForm(const std::string& name, unsigned int grade, unsigned int exec);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		const std::string& getName() const;
		const bool& getSigned() const;
		unsigned int getGrade() const;
		unsigned int getExec() const;
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
