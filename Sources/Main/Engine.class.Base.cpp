/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Base.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:20:07 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 15:18:58 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Main/Engine.class.hpp"
#include "Views/AView.class.hpp"

int		Engine::Run(void)
{
	std::string					Command;
	char						Player = 1;

	this->IO->Init();
	while (this->FreeSpaceExists() && !this->CheckWin(this->Field))
	{
		this->Views[CurrView]->Display();
		this->IO->ClearErrorMsgs();
		try
		{
			Command = std::to_string(static_cast<int>(Player)) + ",* ";
			Command.append(this->IO->ReadInput());
			this->CurrView = this->Views[CurrView]->Execute(Command);
		}
		catch (WrongInputError &e)
		{
			this->IO->AddErrorMsg(e.what());
		}
		catch (Engine::PositionOutOfRangeError &e)
		{
			this->IO->AddErrorMsg(e.what());
		}
		catch (Engine::PositionOccupiedError &e)
		{
			this->IO->AddErrorMsg(e.what());
		}
	}
	this->IO->DisplayGame(this->Field);
	return (0);
}

void	Engine::Set(char Player, size_t y, size_t x)
{
	if (x >= this->Field.size() || y >= this->Field.size())
		throw Engine::PositionOutOfRangeError(y, x);
	if (this->Field[y][x] != 0)
		throw Engine::PositionOccupiedError(y, x);
	this->Field[y][x] = Player;
}

bool	Engine::FreeSpaceExists(void) const
{
	for (size_t i = 0; i < this->Field.size(); i++)
		if (std::find(this->Field[i].begin(), this->Field[i].end(), 0) != this->Field[i].end())
			return (true);
	return (false);
}
