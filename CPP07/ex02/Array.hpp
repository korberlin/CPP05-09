/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:54:42 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 16:54:43 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <string>
#include <iostream>

template<typename T>
class Array {
	private:
		T* _elements;
		unsigned int n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;
};

template<typename T>
Array<T>::Array(): _elements(NULL), n(0) {

}

template<typename T>
Array<T>::Array(unsigned int n) {
	 this->n = n;
	 _elements = new T[n];
}

template<typename T>
Array<T>::Array(const Array& other):_elements(NULL), n(0) {
	*this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _elements;
		this->n = other.n;
		this->_elements = new T[n];
		for (unsigned int i = 0; i < n; i++) {
			_elements[i] = other._elements[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array(){
	if (this->_elements)
		delete[] _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= n)
		throw std::out_of_range("index is out of range");
	else
		return _elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= n)
		throw std::out_of_range("index is out of range");
	else
		return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return n;
}

#endif
