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
	mvprintw(static_cast<int>(4), 0, "Type 'Menu' to enter game menu");
	for (i = 0; i < this->ErrorMsgs.size() && (i + 4) < static_cast<size_t>(y - 1); i++)
		mvprintw(static_cast<int>(i + 4), 0, this->ErrorMsgs[i].c_str());
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
