/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameView.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:11:47 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 16:20:21 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Main/GameView.class.hpp"

AView*		GameView::Execute(std::string const &Input, char Player)
{
	std::regex		Reg;
	std::smatch		Match;

	Reg.assign("([[:d:]]+)[[:s:]]+([[:d:]]+)");
	if (std::regex_match(Input, Match, Reg))
	{
		this->_Engine.Set(Player, std::stoi(Match.str(1)), std::stoi(Match.str(2)));
		return (nullptr);
	}
	throw WrongInputError(Input);
}
