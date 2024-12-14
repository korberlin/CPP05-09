#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	// Example with std::vector<int>
	{
		std::vector<int> vec;
		// Populate the vector
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);

		// Test case where value is present
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 20);
			std::cout << "Found in vector: " << *it << std::endl;
		}
		catch (const char *msg)
		{
			std::cerr << "Vector error: " << msg << std::endl;
		}

		// Test case where value is not present
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 40);
			std::cout << "Found in vector: " << *it << std::endl;
		}
		catch (const char *msg)
		{
			std::cerr << "Vector error: " << msg << std::endl;
		}
	}

	// Example with std::list<int>
	{
		std::list<int> lst;
		// Populate the list
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(300);

		// Test case where value is present
		try
		{
			std::list<int>::iterator it = easyfind(lst, 200);
			std::cout << "Found in list: " << *it << std::endl;
		}
		catch (const char *msg)
		{
			std::cerr << "List error: " << msg << std::endl;
		}

		// Test case where value is not present
		try
		{
			std::list<int>::iterator it = easyfind(lst, 400);
			std::cout << "Found in list: " << *it << std::endl;
		}
		catch (const char *msg)
		{
			std::cerr << "List error: " << msg << std::endl;
		}
	}

	// Example with std::deque<int>
	{
		std::deque<int> deq;
		// Populate the deque
		deq.push_back(1000);
		deq.push_back(2000);
		deq.push_back(3000);

		// Test case where value is present
		try
		{
			std::deque<int>::iterator it = easyfind(deq, 2000);
			std::cout << "Found in deque: " << *it << std::endl;
		}
		catch (const char *msg)
		{
			std::cerr << "Deque error: " << msg << std::endl;
		}

		// Test case where value is not present
		try
		{
			std::deque<int>::iterator it = easyfind(deq, 4000);
			std::cout << "Found in deque: " << *it << std::endl;
		}
		catch (const char *msg)
		{
			std::cerr << "Deque error: " << msg << std::endl;
		}
	}

	return 0;
}
