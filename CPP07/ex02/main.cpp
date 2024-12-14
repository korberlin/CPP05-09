/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:54:44 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 16:54:45 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
	// Create arrays of different types
	Array<int>        integerArray(5);
	Array<std::string> stringArray(3);
	Array<double>     doubleArray(4);

	// Initialize integerArray with values
	for (unsigned int i = 0; i < integerArray.size(); ++i)
		integerArray[i] = static_cast<int>(i * 10);

	// Initialize stringArray with values
	stringArray[0] = "C++";
	stringArray[1] = "Templates";
	stringArray[2] = "Are Powerful";

	// Initialize doubleArray with values
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
		doubleArray[i] = i + 0.123;

	// Display integerArray
	std::cout << "=== Integer Array ===" << std::endl;
	for (unsigned int i = 0; i < integerArray.size(); ++i)
		std::cout << "Element " << i << ": " << integerArray[i] << std::endl;
	std::cout << std::endl;

	// Display stringArray
	std::cout << "=== String Array ===" << std::endl;
	for (unsigned int i = 0; i < stringArray.size(); ++i)
		std::cout << "Element " << i << ": " << stringArray[i] << std::endl;
	std::cout << std::endl;

	// Display doubleArray
	std::cout << "=== Double Array ===" << std::endl;
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
		std::cout << "Element " << i << ": " << doubleArray[i] << std::endl;
	std::cout << std::endl;

	// Test copy constructor
	std::cout << "Testing copy constructor with integerArrayCopy..." << std::endl;
	Array<int> integerArrayCopy(integerArray);
	integerArrayCopy[0] = 999; // Modify the copy
	std::cout << "Original integerArray[0]: " << integerArray[0] << std::endl;
	std::cout << "Copied integerArrayCopy[0]: " << integerArrayCopy[0] << std::endl;
	std::cout << std::endl;

	// Test assignment operator
	std::cout << "Testing assignment operator with doubleArrayAssigned..." << std::endl;
	Array<double> doubleArrayAssigned;
	doubleArrayAssigned = doubleArray;
	doubleArrayAssigned[1] = 3.1415; // Modify the assigned array
	std::cout << "Original doubleArray[1]: " << doubleArray[1] << std::endl;
	std::cout << "Assigned doubleArrayAssigned[1]: " << doubleArrayAssigned[1] << std::endl;
	std::cout << std::endl;

	// Test exception handling with out-of-bounds access
	std::cout << "Testing exception handling..." << std::endl;
	try {
		std::cout << integerArray[integerArray.size()] << std::endl; // Out of bounds
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test with empty array
	std::cout << "Testing empty array..." << std::endl;
	Array<char> emptyCharArray;
	std::cout << "Size of emptyCharArray: " << emptyCharArray.size() << std::endl;
	try {
		emptyCharArray[0] = 'A'; // Should throw exception
	} catch (const std::exception& e) {
		std::cout << "Caught exception when accessing empty array: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Modify original arrays to ensure deep copies
	std::cout << "Modifying original arrays to test deep copy..." << std::endl;
	integerArray[1] = 111;
	doubleArray[2] = 2.7182;
	std::cout << "Modified integerArray[1]: " << integerArray[1] << std::endl;
	std::cout << "integerArrayCopy[1] remains: " << integerArrayCopy[1] << std::endl;
	std::cout << "Modified doubleArray[2]: " << doubleArray[2] << std::endl;
	std::cout << "doubleArrayAssigned[2] remains: " << doubleArrayAssigned[2] << std::endl;

	return 0;
}
