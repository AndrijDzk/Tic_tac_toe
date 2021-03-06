/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartMenuView.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:50:21 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:05:06 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Views/StartMenuView.class.hpp"

size_t		Engine::StartMenuView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign(R"(O)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.Players = OnePlayer;
		this->Eng.CurrPlayer = 1;
		this->Eng.ClearField();
		return (GAME_VIEW);
	}
	Reg.assign(R"(T)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.Players = TwoPlayers;
		this->Eng.CurrPlayer = 1;
		this->Eng.ClearField();
		return (GAME_VIEW);
	}
	Reg.assign(R"(C)");
	if (std::regex_match(Input, Match, Reg))
		return (CHANGE_OUTPUT_MODE_VIEW);
	Reg.assign(R"(E)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.ClearField();
		throw Engine::Exit();
	}
	throw WrongInputError();
}

void		Engine::StartMenuView::Display(void)
{
	this->Eng.IO->DisplayStartMenu();
}