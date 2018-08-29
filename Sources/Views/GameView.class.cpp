/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameView.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:11:47 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:51:18 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Main/AI.class.hpp"
#include "Views/GameView.class.hpp"

size_t		Engine::GameView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;
	t_Point			AIMove;

	Reg.assign(R"(([[:d:]]+)[[:s:]]+([[:d:]]+))");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.Set(this->Eng.CurrPlayer, std::stoi(Match.str(1)), std::stoi(Match.str(2)));
		if (this->Eng.CheckGameOver())
			return (GAME_OVER_VIEW);
		this->Eng.ChangePlayer();
		if (this->Eng.Players == OnePlayer)
		{
			AIMove = this->Eng.Skynet->MakeMove(this->Eng.CurrPlayer, this->Eng.Field);
			this->Eng.Set(this->Eng.CurrPlayer, AIMove.first, AIMove.second);
			if (this->Eng.CheckGameOver())
				return (GAME_OVER_VIEW);
			this->Eng.ChangePlayer();
		}
		return (GAME_VIEW);
	}
	Reg.assign(R"(Menu)");
	if (std::regex_match(Input, Match, Reg))
		return (GAME_MENU_VIEW);
	throw WrongInputError();
}

void		Engine::GameView::Display(void)
{
	this->Eng.IO->DisplayGame(this->Eng.Field);
}
