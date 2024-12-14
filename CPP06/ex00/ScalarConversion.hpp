/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:49:57 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:51:30 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConversion {
	private:
		ScalarConversion();
		ScalarConversion(const ScalarConversion& other);
		ScalarConversion& operator=(const ScalarConversion& other);
		~ScalarConversion();
	public:
		static void convert(const std::string& literal);
};

#endif
