/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:54:26 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 16:54:27 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template<typename T>
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template<typename T>
T min(T x, T y) {
	return (x < y ? x : y);
}

template<typename T>
T max(T x, T y) {
	return (x > y ? x : y);
}

#endif
