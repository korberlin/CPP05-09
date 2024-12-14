/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <	gkoksal@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:07:09 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/17 23:10:01 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	std::cout << "====================== Starting Tests ==========================" << std::endl;

	// 1st Test: RobotomyRequestForm
	std::cout << "------------------------------ 1st test ------------------------" << std::endl;
	try {
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "Wall-E");
		Bureaucrat executor("SuperAdmin", 2);
		executor.signForm(*form);
		executor.executeForm(*form);
		delete form;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	} 
	// 2nd Test: PresidentialPardonForm
	std::cout << "------------------------------ 2nd test ------------------------" << std::endl;
	try {
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Zaphod Beeblebrox"); 
		Bureaucrat highRank("President", 1); 
		highRank.signForm(*form);
		highRank.executeForm(*form); 
		delete form;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	} 
	// 3rd Test: ShrubberyCreationForm
	std::cout << "------------------------------ 3rd test ------------------------" << std::endl;
	try {
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "Central Park");
		Bureaucrat gardener("HeadGardener", 10);
		gardener.signForm(*form);
		gardener.executeForm(*form);
		delete form;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	} 
	// 4th Test: Invalid Form Request
	std::cout << "------------------------------ 4th test ------------------------" << std::endl;
	try {
		Intern intern;
		AForm *form = intern.makeForm("invalid form", "Nobody");
		(void)form; // This line won't execute due to the exception
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	} 
	// 5th Test: Insufficient Grade for Execution
	std::cout << "------------------------------ 5th test ------------------------" << std::endl;
	try {
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "R2-D2");

		Bureaucrat lowRank("JuniorBureaucrat", 150);

		lowRank.signForm(*form);
		lowRank.executeForm(*form); // Should fail due to insufficient grade

		delete form;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	}
	std::cout << "======================= All Tests Done =========================" << std::endl;
	return 0;
}
