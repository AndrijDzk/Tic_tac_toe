/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConsoleIO.class.Base.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:56:13 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 15:32:43 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>

#include "IO/ConsoleIO.class.hpp"

void			ConsoleIO::Init(void) {}

void			ConsoleIO::DeInit(void) {}

std::string		ConsoleIO::ReadInput(void)
{
	std::string					Buff;

	std::getline(std::cin, Buff);
	return (Buff);
}
