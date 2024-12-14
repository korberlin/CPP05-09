/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:02 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 13:50:03 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data *data = new Data;
	data->id = 5;
	data->name = "5th data";
	uintptr_t serialized = Serializer::serialize(data);
	Data *	deserialized = Serializer::deserialize(serialized);

	std::cout << std::dec << serialized << std::endl;
	std::cout << serialized << std::endl;
	std::cout << data << std::endl;
	std::cout << deserialized <<  std::endl;
	std::cout << data->id << std::endl;
	std::cout << deserialized->id <<  std::endl;
	std::cout << data->name << std::endl;
	std::cout << deserialized->name <<  std::endl;
	delete data;
}
