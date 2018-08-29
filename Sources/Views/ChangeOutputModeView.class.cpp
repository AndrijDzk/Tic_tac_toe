/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChangeOutputModeView.class.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:43:16 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:20:29 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Views/ChengeOutputModeView.class.hpp"

size_t		Engine::ChangeOutputModeView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign(R"(C)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.ChangeOutputMode(AIOFactory::Console);
		return (this->Eng.PrevView);
	}
	Reg.assign(R"(n)");
	if (std::regex_match(Input, Match, Reg))
	{
#ifdef NCURSES_ON
		this->Eng.ChangeOutputMode(AIOFactory::ncurses);
		return (this->Eng.PrevView);
#else
		return (CHANGE_OUTPUT_MODE_VIEW);
#endif
	}
	Reg.assign(R"(B)");
	if (std::regex_match(Input, Match, Reg))
		return (this->Eng.PrevView);
	throw WrongInputError();
}

void		Engine::ChangeOutputModeView::Display(void)
{
	this->Eng.IO->DisplayChangeOutputMenu();
}
