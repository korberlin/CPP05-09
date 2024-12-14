/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:49:55 by gkoksal           #+#    #+#             */
/*   Updated: 2024/12/03 14:49:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion() {

}

ScalarConversion::ScalarConversion(const ScalarConversion& other) {
	*this = other;
}

ScalarConversion& ScalarConversion::operator=(const ScalarConversion& other) {
	(void)other;
	return *this;
}

ScalarConversion::~ScalarConversion() {

}

void ScalarConversion::convert(const std::string& literal) {
	double d;
	bool isConversionValid = false;
	bool isNan = false;
	bool isInf = false;

	// Handle special literals and single-character inputs
	if (literal == "nan" || literal == "nanf") {
		d = std::numeric_limits<double>::quiet_NaN();
		isNan = true;
		isConversionValid = true;
	} else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
		d = std::numeric_limits<double>::infinity();
		isInf = true;
		isConversionValid = true;
	} else if (literal == "-inf" || literal == "-inff") {
		d = -std::numeric_limits<double>::infinity();
		isInf = true;
		isConversionValid = true;
	} else if (literal.length() == 1 && !std::isdigit(literal[0])) {
		// Treat any single non-digit character as a character input
		d = static_cast<double>(literal[0]);
		isConversionValid = true;
	} else {
		// Handle float literals ending with 'f'
	std::string input = literal;
	if (!input.empty() && input[input.size() - 1] == 'f' && input != "f") {
		input = input.substr(0, input.size() - 1);
	}
		// Try parsing as double
		char *endPtr;
		d = std::strtod(input.c_str(), &endPtr);
		isConversionValid = (endPtr != input.c_str()) && (*endPtr == '\0');
		isNan = std::isnan(d);
		isInf = std::isinf(d);
	}

	if (!isConversionValid) {
		// Invalid input
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// Output char conversion
	std::cout << "char: ";
	if (isNan || isInf || d < 0 || d > 127) {
		std::cout << "impossible" << std::endl;
	} else {
		char c = static_cast<char>(d);
		if (std::isprint(c)) {
			std::cout << "'" << c << "'" << std::endl;
		} else {
			std::cout << "non displayable" << std::endl;
		}
	}

	// Output int conversion
	std::cout << "int: ";
	if (isNan || isInf || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max())) {
		std::cout << "impossible" << std::endl;
	} else {
		int i = static_cast<int>(d);
		std::cout << i << std::endl;
	}

	// Output float conversion
	std::cout << "float: ";
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1);
	if (isNan) {
		std::cout << "nanf" << std::endl;
	} else if (isInf) {
		std::cout << ((d > 0) ? "+inff" : "-inff") << std::endl;
	} else {
		std::cout << f << "f" << std::endl;
	}

	// Output double conversion
	std::cout << "double: ";
	if (isNan) {
		std::cout << "nan" << std::endl;
	} else if (isInf) {
		std::cout << ((d > 0) ? "+inf" : "-inf") << std::endl;
	} else {
		std::cout << d << std::endl;
	}
}

