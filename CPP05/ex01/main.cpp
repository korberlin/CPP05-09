/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:06 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:46:07 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		// Create a Bureaucrat with a valid grade
		Bureaucrat bureaucrat1("Alice", 50);

		// Create a Form with valid grades
		Form form1("Tax Form", 45, 30);

		// Try to sign the form with a Bureaucrat who doesn't meet the signing grade
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;

		// Create a Bureaucrat with a high enough grade
		Bureaucrat bureaucrat2("Bob", 40);

		// Try to sign the form with a qualified Bureaucrat
		bureaucrat2.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	// Test invalid Form creation
	try {
		Form invalidForm("Invalid Form", 0, 20); // Grade is too high (0 is invalid)
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	// Test invalid Bureaucrat creation
	try {
		Bureaucrat invalidBureaucrat("Charlie", 151); // Grade is too low
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
