/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameView.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:11:47 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 14:34:32 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Main/AI.class.hpp"
#include "Views/GameView.class.hpp"
#include "Views/GameMenuView.class.hpp"

size_t		Engine::GameView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;
	t_Point			AIMove;
	char			Player;

	Reg.assign(R"(([[:d:]]+),(\*|O)[[:s:]]([[:d:]]+)[[:s:]]+([[:d:]]+))");
	if (std::regex_match(Input, Match, Reg))
	{
		if (std::stoi(Match.str(1)) > 127)
			throw std::runtime_error("Wrong Player: " + Match.str(1));
		Player = static_cast<char>(std::stoi(Match.str(1)));
		this->Eng.Set(Player, std::stoi(Match.str(3)), std::stoi(Match.str(4)));
		if (Player == 1)
			Player = 2;
		else
			Player = 1;
		if (Match.str(2) == "*" && this->Eng.FreeSpaceExists())
		{
			AIMove = this->Eng.Skynet->MakeMove(Player, this->Eng.Field);
			this->Eng.Set(Player, AIMove.first, AIMove.second);
		}
		return (GAME_VIEW);
	}
	Reg.assign(R"([[:d:]]+,(\*|O)[[:s:]]+Menu)");
	if (std::regex_match(Input, Match, Reg))
		return (GAME_MENU_VIEW);
	throw WrongInputError();
}

void		Engine::GameView::Display(void)
{
	this->Eng.IO->DisplayGame(this->Eng.Field);
}
