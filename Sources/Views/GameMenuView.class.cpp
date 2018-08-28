/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameMenuView.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:33:23 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 15:04:28 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Views/GameMenuView.class.hpp"

size_t		Engine::GameMenuView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign(R"([[:d:]]+,(\*|O)[[:s:]]+R)");
	if (std::regex_match(Input, Match, Reg))
		return (GAME_VIEW);
	throw WrongInputError();
}

void		Engine::GameMenuView::Display(void)
{
	this->Eng.IO->DisplayGameMenu();
}
