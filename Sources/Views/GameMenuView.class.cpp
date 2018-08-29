/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameMenuView.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:33:23 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 13:59:05 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Views/GameMenuView.class.hpp"

size_t		Engine::GameMenuView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign(R"(R)");
	if (std::regex_match(Input, Match, Reg))
		return (GAME_VIEW);
	Reg.assign(R"(C)");
	if (std::regex_match(Input, Match, Reg))
		return (CHANGE_OUTPUT_MODE_VIEW);
	Reg.assign(R"(M)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.Players = OnePlayer;
		this->Eng.CurrPlayer = 1;
		this->Eng.ClearField();
		return (START_MENU_VIEW);
	}
	throw WrongInputError();
}

void		Engine::GameMenuView::Display(void)
{
	this->Eng.IO->DisplayGameMenu();
}
