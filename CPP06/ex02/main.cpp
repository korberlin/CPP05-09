/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:21 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:50:22 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main(void) {
	Base *ptr = generate();
	Base& ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
}
