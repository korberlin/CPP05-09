/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:19 by gkoksal           #+#    #+#             */
/*   Updated: 2024/12/03 14:58:42 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Base {
	public:
	virtual ~Base();

};

class A: public Base {

};

class B: public Base {

};

class C: public Base {

};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
