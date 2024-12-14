/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:16 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:50:17 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base::~Base(){

}

Base* generate(void) {
	Base *ptr;
	srand((unsigned)time(0));
	int i = (rand() % 3);
	if (i == 0)
		return (ptr = new A);
	else if (i == 1)
		return (ptr = new B);
	else
		return (ptr = new C);
}

void identify(Base* p) {
	std::cout << "Created class is ";
	A *a_ptr = dynamic_cast<A*>(p);
	B *b_ptr = dynamic_cast<B*>(p);
	if (a_ptr)
		std::cout << "A" << std::endl;
	else if (b_ptr)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	std::cout << "Created class is ";
	try {
		A &a_ref = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a_ref;
		return;
	}
	catch (...) { }
	try {
		B &b_ref = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b_ref;
		return;
	}
	catch(...) { }
	std::cout << "C" << std::endl;
}
