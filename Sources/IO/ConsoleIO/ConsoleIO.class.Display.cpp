/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConsoleIO.class.DisplayGame.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:59:51 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 12:42:19 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Main/Defines.hpp"

#include "IO/ConsoleIO.class.hpp"

void		ConsoleIO::DisplayGame(std::vector<std::vector<char>> const &Field)
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
	std::cout << "Type '[y] [x]' to make move" << std::endl;
	std::cout << "Type 'Menu' to enter game menu" << std::endl;
	for (i = 0; i < this->ErrorMsgs.size(); i++)
		std::cout << this->ErrorMsgs[i] << std::endl;
}

void		ConsoleIO::DisplayGameMenu(void)
{
	std::vector<std::string>	Options = {
									"[R]esume",
									"[C]hange output mode",
									"[M]ain menu"};

	this->DisplayMenu(Options);
}

void		ConsoleIO::DisplayStartMenu(void)
{
	std::vector<std::string>	Options = {
									"[O]ne player",
									"[T]wo players",
									"[C]hange output mode",
									"[E]xit"};

	this->DisplayMenu(Options);
}

void		ConsoleIO::DisplayChangeOutputMenu(void)
{
	std::vector<std::string>	Options = {
									"[C]onsole",
									"[n]cruses",
									"[B]ack"};

#ifndef NCURSES_ON
	Options[1].append(" (unavailable)");
#endif
	this->DisplayMenu(Options);
}

void		ConsoleIO::DisplayGameOver(char Player)
{
	std::vector<std::string>	Options = {
									"Game Over!",
									"Player " + std::to_string(static_cast<int>(Player)) + " won",
									"[B]ack to Main menu"};

	if (Player == 0)
		Options[1] = "Draw";
	this->DisplayMenu(Options);
}

void		ConsoleIO::DisplayMenu(std::vector<std::string> const &Options)
{
	for (size_t i = 0; i < Options.size(); i++)
		std::cout << Options[i] << std::endl;
}
