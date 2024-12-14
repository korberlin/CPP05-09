/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:11:05 by gkoksal           #+#    #+#             */
/*   Updated: 2024/12/04 13:15:27 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
	// Test 1: Basic operations with MutantStack
	std::cout << "Test 1: Basic operations with MutantStack" << std::endl;
	MutantStack<int> mstack;

	// Using std::stack member functions
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl; // Should output 17

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl; // Should output 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Using iterators
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Elements in MutantStack using iterator:" << std::endl;
	for (; it != ite; ++it)
		std::cout << *it << std::endl;

	// Test 2: Copy constructor
	std::cout << "\nTest 2: Copy constructor" << std::endl;
	MutantStack<int> mstack_copy(mstack);

	std::cout << "Elements in MutantStack copy:" << std::endl;
	for (MutantStack<int>::iterator it_copy = mstack_copy.begin(); it_copy != mstack_copy.end(); ++it_copy)
		std::cout << *it_copy << std::endl;

	// Test 3: Assignment operator
	std::cout << "\nTest 3: Assignment operator" << std::endl;
	MutantStack<int> mstack_assigned;
	mstack_assigned = mstack;

	std::cout << "Elements in MutantStack assigned:" << std::endl;
	for (MutantStack<int>::iterator it_assign = mstack_assigned.begin(); it_assign != mstack_assigned.end(); ++it_assign)
		std::cout << *it_assign << std::endl;

	// Test 4: Comparison with std::list
	std::cout << "\nTest 4: Comparison with std::list" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Elements in std::list:" << std::endl;
	for (std::list<int>::iterator it_list = lst.begin(); it_list != lst.end(); ++it_list)
		std::cout << *it_list << std::endl;

	// Test 5: Using const_iterators
	std::cout << "\nTest 5: Using const_iterators" << std::endl;
	const MutantStack<int> const_mstack(mstack);

	MutantStack<int>::const_iterator cit = const_mstack.begin();
	MutantStack<int>::const_iterator cite = const_mstack.end();

	std::cout << "Elements in const MutantStack:" << std::endl;
	for (; cit != cite; ++cit)
		std::cout << *cit << std::endl;

	// Test 6: Empty MutantStack
	std::cout << "\nTest 6: Empty MutantStack" << std::endl;
	MutantStack<int> empty_stack;
	if (empty_stack.empty())
		std::cout << "MutantStack is empty." << std::endl;
	else
		std::cout << "MutantStack is not empty." << std::endl;

	// Test 7: Using different underlying container (std::vector)
	std::cout << "\nTest 7: Using different underlying container (std::vector)" << std::endl;
	MutantStack<int, std::vector<int> > mstack_vector;
	mstack_vector.push(1);
	mstack_vector.push(2);
	mstack_vector.push(3);

	std::cout << "Elements in MutantStack with std::vector as underlying container:" << std::endl;
	for (MutantStack<int, std::vector<int> >::iterator it_vec = mstack_vector.begin(); it_vec != mstack_vector.end(); ++it_vec)
		std::cout << *it_vec << std::endl;

	// Test 8: Modifying elements via iterators
	std::cout << "\nTest 8: Modifying elements via iterators" << std::endl;
	it = mstack.begin();
	ite = mstack.end();

	for (; it != ite; ++it)
		*it += 100; // Add 100 to each element

	std::cout << "Elements in MutantStack after modification:" << std::endl;
	for (it = mstack.begin(); it != ite; ++it)
		std::cout << *it << std::endl;

	// Test 9: Stack operations after iterator modification
	std::cout << "\nTest 9: Stack operations after iterator modification" << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl; // Should reflect the modified value

	mstack.pop();
	std::cout << "Top element after pop: " << mstack.top() << std::endl;

	std::cout << "Final size of MutantStack: " << mstack.size() << std::endl;

	return 0;
}
