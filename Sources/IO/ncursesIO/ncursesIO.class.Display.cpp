/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesIO.class.DisplayGame.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:59:51 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 14:31:04 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#include "IO/ncursesIO.class.hpp"

#ifdef NCURSES_ON

void		ncursesIO::DisplayGame(std::vector<std::vector<char>> const &Field)
{
	size_t		i;
	int			x;
	int			y;

	getmaxyx(stdscr, y, x);
	if (y < 10 || x < 35)
		throw ncursesIO::WindowTooSmallError(y, x);
	clear();
	for (i = 0; i < Field.size(); i++)
		for (size_t j = 0; j < Field.size(); j++)
		{
			if (Field[i][j] == 1)
				mvaddch(i, j, 'X');
			else if (Field[i][j] == 2)
				mvaddch(i, j, 'O');
			else
				mvaddch(i, j, '.');
		}
	mvprintw(4, 0, "Type '[y] [x]' to make move");
	mvprintw(5, 0, "Type 'Menu' to enter game menu");
	for (i = 0; i < this->ErrorMsgs.size() && (5 + i) < static_cast<size_t>(y - 1); i++)
		mvprintw(static_cast<int>(5 + i), 0, this->ErrorMsgs[i].c_str());
	move(y - 1, 0);
	refresh();
}

void		ncursesIO::DisplayGameMenu(void)
{
	std::vector<std::string>		Options = {
							"[R]esume",
							"[C]hange output mode",
							"[M]ain menu"};

	this->DisplayMenu(Options);
}

void		ncursesIO::DisplayStartMenu(void)
{
	std::vector<std::string>	Options = {
									"[O]ne player",
									"[T]wo players",
									"[C]hange output mode",
									"[E]xit"};

	this->DisplayMenu(Options);
}

void		ncursesIO::DisplayChangeOutputMenu(void)
{
	std::vector<std::string>	Options = {
									"[C]onsole",
									"[n]cruses",
									"[B]ack"};

	this->DisplayMenu(Options);
}

void		ncursesIO::DisplayGameOver(char Player)
{
	std::vector<std::string>	Options = {
									"Game Over!",
									"Player " + std::to_string(static_cast<int>(Player)) + " won",
									"[B]ack to Main menu"};

	if (Player == 0)
		Options[1] = "Draw";
	this->DisplayMenu(Options);
}

void		ncursesIO::DisplayMenu(std::vector<std::string> const &Options)
{
	size_t							i;
	int								x;
	int								y;
	int								Xstart;
	int								Ystart;


	getmaxyx(stdscr, y, x);
	if (y < static_cast<int>(Options.size() + 1) || x < 15)
		throw ncursesIO::WindowTooSmallError(y, x);
	clear();
	for (i = 0; i < Options.size(); i++)
	{
		if (static_cast<int>(Options[i].size()) < x)
			Xstart = (x - static_cast<int>(Options[i].size()))/2;
		else
			Xstart = 0;
		Ystart = i*y/(Options.size() + 1);
		mvprintw(Ystart, Xstart, Options[i].c_str());
	}
	move(y - 1, 0);
	refresh();
}


#endif
