/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesIO.class.Base.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:02:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 15:21:56 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "IO/ncursesIO.class.hpp"

#ifdef NCURSES_ON

#include <ncurses.h>

void				ncursesIO::Init(void)
{
	int		y;
	int 	x;

	initscr();
	getmaxyx(stdscr, y, x);
	if (y < 20 || x < 20)
	{
		endwin();
		throw AInputOutput::InitError();
	}
}

void				ncursesIO::DeInit(void)
{
	endwin();
}

std::string			ncursesIO::ReadInput(void)
{
	char								Buff[10];

	bzero(Buff, 10);
	getnstr(Buff, 9);
	return (std::string(Buff));
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
