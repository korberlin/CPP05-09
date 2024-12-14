/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:02 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:47:03 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int				_grade;
		Bureaucrat();
	public:
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		unsigned int	getGrade(void) const;
		const std::string&	getName(void) const;
		void increment();
		void decrement();
		void signForm(AForm& other);
		void executeForm(const AForm& form);
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
