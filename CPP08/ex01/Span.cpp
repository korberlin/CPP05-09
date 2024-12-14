/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:56 by gkoksal           #+#    #+#             */
/*   Updated: 2024/12/04 13:19:57 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) {

}

Span::Span(unsigned int N): _maxSize(N) {

}

Span::Span(const Span& other): _maxSize(other._maxSize), _numbers(other._numbers) {

}

Span& Span::operator=(const Span& other) {
	if (this != &other){
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(void) {

}

std::vector<int>& Span::getNumbers(void){
	return (_numbers);
}

int	Span::shortestSpan(void) {
	if (_numbers.size() < 2)
		throw std::logic_error("Array is too small");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; i++){
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan(void) {
	if (_numbers.size() < 2)
		throw std::logic_error("Array is too small");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::size_t distance = std::distance(begin, end);
	if (_numbers.size() + distance > _maxSize)
		throw std::out_of_range("Cannot add numbers, Span will exceed the capacity");
	_numbers.insert(_numbers.end(), begin, end);
}

void Span::addNumber(int n) {
	if (_numbers.size() >= _maxSize) {
		throw std::out_of_range("Span array is already full");
	}
	_numbers.push_back(n);
}
