/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:54:37 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 16:54:37 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void printElement(T &element) {
	std::cout << element << " ";
}

// Function to increment numeric elements
template <typename T>
void increment(T &element) {
	++element;
}

// Function to append a string to std::string elements
void appendExclamation(std::string &element) {
	element += "!";
}

int main()
{
	// Test with int array
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	iter(intArray, intLength, increment);

	std::cout << "Modified int array after increment: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl
			  << std::endl;

	// Test with float array
	float floatArray[] = {1.5f, 2.5f, 3.5f};
	size_t floatLength = sizeof(floatArray) / sizeof(floatArray[0]);

	std::cout << "Original float array: ";
	iter(floatArray, floatLength, printElement);
	std::cout << std::endl;

	iter(floatArray, floatLength, increment);

	std::cout << "Modified float array after increment: ";
	iter(floatArray, floatLength, printElement);
	std::cout << std::endl
			  << std::endl;

	// Test with std::string array
	std::string stringArray[] = {"Hello", "World", "Templates"};
	size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "Original string array: ";
	iter(stringArray, stringLength, printElement);
	std::cout << std::endl;

	iter(stringArray, stringLength, appendExclamation);

	std::cout << "Modified string array after append: ";
	iter(stringArray, stringLength, printElement);
	std::cout << std::endl
			  << std::endl;

	return 0;
}
