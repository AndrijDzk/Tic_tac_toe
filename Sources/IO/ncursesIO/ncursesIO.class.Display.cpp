/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesIO.class.Display.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:59:51 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 14:31:04 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "IO/ncursesIO.class.hpp"

#ifdef NCURSES_ON

void		ncursesIO::Display(std::vector<std::vector<char>> const &Field)
{
	size_t		i;
	int			x;
	int			y;

	getmaxyx(stdscr, y, x);
	if (y < 4 || x < 4)
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
	for (i = 0; i < this->ErrorMsgs.size() && (i + 3) < static_cast<size_t>(y - 1); i++)
		mvprintw(static_cast<int>(i + 3), 0, this->ErrorMsgs[i].c_str());
	move(y - 1, 0);
	refresh();
}

void		ncursesIO::AddErrorMsg(std::string const &Msg)
{
	this->ErrorMsgs.push_back(Msg);
}

void		ncursesIO::ClearErrorMsgs(void)
{
	this->ErrorMsgs.clear();
}

#endif
