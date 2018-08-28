/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChangeOutputModeView.class.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:43:16 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 15:43:16 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/Defines.hpp"

#include "Views/ChengeOutputModeView.class.hpp"

size_t		Engine::ChangeOutputModeView::Execute(std::string const &Input)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign(R"([[:d:]]+,(\*|O)[[:s:]]+O)");
	if (std::regex_match(Input, Match, Reg))
		return (GAME_VIEW);
	throw WrongInputError();
}

void		Engine::ChangeOutputModeView::Display(void)
{
	this->Eng.IO->DisplayChangeOutputMenu();
}
