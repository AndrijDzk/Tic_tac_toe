/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameOverView.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:27:46 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:27:46 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Views/GameOverView.class.hpp"

size_t		Engine::GameOverView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign(R"(B)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->Eng.Players = OnePlayer;
		this->Eng.CurrPlayer = 1;
		this->Eng.ClearField();
		return (START_MENU_VIEW);
	}
	throw WrongInputError();
}

void		Engine::GameOverView::Display(void)
{
	this->Eng.IO->DisplayGameOver(this->Eng.CurrPlayer);
}