/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:53 by gkoksal           #+#    #+#             */
/*   Updated: 2024/12/10 11:57:23 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// Initialize random seed
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	try {
		// Test 1: Basic functionality with small numbers
		std::cout << "Test 1: Basic functionality with small numbers" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected output: 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	  // Expected output: 14

		// Test 2: Adding number beyond capacity
		std::cout << "\nTest 2: Adding number beyond capacity" << std::endl;
		try {
			sp.addNumber(42); // Should throw an exception
		}
		catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		// Test 3: Computing spans with insufficient numbers
		std::cout << "\nTest 3: Computing spans with insufficient numbers" << std::endl;
		Span sp2(1);
		sp2.addNumber(5);
		try {
			sp2.shortestSpan(); // Should throw an exception
		}
		catch (const std::exception &e) {
			std::cerr << "Exception caught when computing shortestSpan: " << e.what() << std::endl;
		}
		try {
			sp2.longestSpan(); // Should throw an exception
		}
		catch (const std::exception &e) {
			std::cerr << "Exception caught when computing longestSpan: " << e.what() << std::endl;
		}

		// Test 4: Filling Span with 10,000 numbers using addNumber()
		std::cout << "\nTest 4: Filling Span with 11,000 numbers using addNumber()" << std::endl;
		Span spLarge(11000);
		for (int i = 0; i < 11000; ++i) {
			spLarge.addNumber(rand());
		}
		std::cout << "Shortest Span in spLarge: " << spLarge.shortestSpan() << std::endl;
		std::cout << "Longest Span in spLarge: " << spLarge.longestSpan() << std::endl;

		// Test 5: Using addNumber() with a range of iterators from a vector
		std::cout << "\nTest 5: Using addNumber() with a range of iterators from a vector" << std::endl;
		std::vector<int> numbers;
		for (int i = 0; i < 10000; ++i) {
			numbers.push_back(rand());
		}
		Span spRange(10000);
		spRange.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest Span in spRange: " << spRange.shortestSpan() << std::endl;
		std::cout << "Longest Span in spRange: " << spRange.longestSpan() << std::endl;

		// Test 6: Exception when adding range exceeding capacity
		std::cout << "\nTest 6: Exception when adding range exceeding capacity" << std::endl;
		try {
			Span spSmall(5);
			spSmall.addNumber(numbers.begin(), numbers.begin() + 10); // Trying to add 10 numbers to capacity of 5
		}
		catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		// Test 7: Empty Span
		std::cout << "\nTest 7: Empty Span" << std::endl;
		Span spEmpty(5);
		try {
			spEmpty.shortestSpan();
		}
		catch (const std::exception &e) {
			std::cerr << "Exception caught when computing shortestSpan: " << e.what() << std::endl;
		}

		// Test 8: Span with duplicate numbers
		std::cout << "\nTest 8: Span with duplicate numbers" << std::endl;
		Span spDuplicate(5);
		spDuplicate.addNumber(10);
		spDuplicate.addNumber(10);
		spDuplicate.addNumber(10);
		spDuplicate.addNumber(10);
		spDuplicate.addNumber(10);
		std::cout << "Shortest Span: " << spDuplicate.shortestSpan() << std::endl; // Expected output: 0
		std::cout << "Longest Span: " << spDuplicate.longestSpan() << std::endl;   // Expected output: 0
	}
	catch (const std::exception &e) {
		std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
	}

	return 0;
}
