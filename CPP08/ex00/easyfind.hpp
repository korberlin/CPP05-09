#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &cont, int i) {
	typename T::iterator iter;
	iter =  std::find(cont.begin(), cont.end(), i);
	if (iter == cont.end())
		throw "Not found";
	return iter;
}


#endif
