/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:49:49 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:49:54 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConversion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert [input]" << std::endl;
		return (1);
	}
	ScalarConversion::convert(av[1]);
	return (0);
}
