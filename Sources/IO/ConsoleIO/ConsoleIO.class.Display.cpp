/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConsoleIO.class.Display.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:59:51 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 12:42:19 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "IO/ConsoleIO.class.hpp"

void		ConsoleIO::Display(std::vector<std::vector<char>> const &Field)
{
	size_t		i;

	for (i = 0; i < Field.size(); i++)
	{
		for (size_t j = 0; j < Field.size(); j++)
		{
			if (Field[i][j] == 1)
				std::cout << 'X';
			else if (Field[i][j] == 2)
				std::cout << 'O';
			else
				std::cout << '.';
		}
		std::cout << std::endl;
	}
	for (i = 0; i < this->ErrorMsgs.size(); i++)
		std::cout << this->ErrorMsgs[i] << std::endl;
}

void		ConsoleIO::AddErrorMsg(std::string const &Msg)
{
	this->ErrorMsgs.push_back(Msg);
}

void		ConsoleIO::ClearErrorMsgs(void)
{
	this->ErrorMsgs.clear();
}
