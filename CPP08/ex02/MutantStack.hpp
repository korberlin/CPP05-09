/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:57:51 by gkoksal           #+#    #+#             */
/*   Updated: 2024/12/04 12:57:52 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack(void) : std::stack<T, Container>() {}
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
		virtual ~MutantStack() {}
		MutantStack &operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T,Container>::operator=(other);
			return *this;
		}
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		iterator begin(void) {return this->c.begin();}
		iterator end(void) {return this->c.end();}
		const_iterator begin(void) const {return this->c.begin(); }
		const_iterator end(void) const {return this->c.end(); }
};

#endif
