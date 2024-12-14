/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:25 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:26 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testRobotomyRequestForm()
{
	std::cout << "----------------- Testing RobotomyRequestForm -----------------" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 30);
		Bureaucrat bob("Bob", 70);
		RobotomyRequestForm form("Alice");

		std::cout << "\nSigning and executing RobotomyRequestForm by Alice:\n";
		alice.signForm(form);
		alice.executeForm(form);

		std::cout << "\nSigning and executing RobotomyRequestForm by Bob:\n";
		bob.signForm(form);	   // Should work since it's already signed
		bob.executeForm(form); // Should throw an exception (grade too low)
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
}

void testPresidentialPardonForm()
{
	std::cout << "------------ Testing PresidentialPardonForm -------------------" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 25);
		PresidentialPardonForm form("Alice");
		PresidentialPardonForm form2("Bob");

		std::cout << "\nSigning and executing PresidentialPardonForm by Alice:\n";
		alice.signForm(form);
		alice.executeForm(form);

		std::cout << "\nExecuting unsigned PresidentialPardonForm by Bob:\n";
		bob.executeForm(form2); // Should throw exception (form not signed)
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
}

void testShrubberyCreationForm()
{
	std::cout << "--------------- Testing ShrubberyCreationForm -----------------" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 50);
		ShrubberyCreationForm form("garden");

		std::cout << "\nSigning and executing ShrubberyCreationForm by Charlie:\n";
		charlie.signForm(form);
		charlie.executeForm(form); // Should create "garden_shrubbery" file
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
}

void testInvalidScenarios()
{
	std::cout << "---------------- Testing Invalid Scenarios --------------------" << std::endl;

	try
	{
		std::cout << "\nTrying to create a Bureaucrat with invalid grade (too low):\n";
		Bureaucrat invalidBureaucrat("Invalid", 151); // Should throw exception
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTrying to create a PresidentialPardonForm with invalid signing:\n";
		Bureaucrat bob("Bob", 26); // Grade too low to sign
		PresidentialPardonForm form("Alice");
		bob.signForm(form); // Should throw exception
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTrying to execute a ShrubberyCreationForm with an unqualified bureaucrat:\n";
		Bureaucrat dave("Dave", 150); // Grade too low to execute
		ShrubberyCreationForm form("forest");
		dave.executeForm(form); // Should throw exception (form not signed or grade too low)
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "====================== Starting Tests ==========================" << std::endl;

	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testShrubberyCreationForm();
	testInvalidScenarios();

	std::cout << "======================= All Tests Done =========================" << std::endl;
	return 0;
}
