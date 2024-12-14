/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:51 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:45:52 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

int main(void) {

	std::cout << "---First Test---" << std::endl;
	try {
		Bureaucrat alex("alex", 1);
		std::cout << alex << std::endl;
		alex.increment(); // Throws an exception
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---Second Test---" << std::endl;
	try {
		Bureaucrat alice("alice", 150);
		std::cout << alice << std::endl;
		alice.decrement(); // Throws an exception
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---Third Test---" << std::endl;
	try {
		Bureaucrat ari("ari", 200); // throws an exception
		std::cout << ari << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
