/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:04 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:05 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _grade;
		const unsigned int _exec;
		Form();
	public:
		Form(const std::string& name, unsigned int grade, unsigned int exec);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
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

};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
