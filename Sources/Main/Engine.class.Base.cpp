/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Base.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:20:07 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 11:30:05 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Main/Engine.class.hpp"
#include "Main/AView.class.hpp"
#include "Main/AI.class.hpp"

int		Engine::Run(void)
{
	std::string					Command;
	AView*						NewView = nullptr;
	char						Player = 1;
	std::pair<size_t, size_t>	AIMove;

	this->IO->Init();
	while (this->FreeSpaceExists() && !this->CheckWin(this->Field))
	{
		this->IO->Display(this->Field);
		this->IO->ClearErrorMsgs();
		try
		{
			Command = this->IO->ReadInput();
			NewView = this->View->Execute(Command, Player);
			Player = 2;
			if (this->FreeSpaceExists() == false)
				return (0);
			AIMove = this->Skynet->MakeMove(Player, this->Field);
			this->Set(Player, AIMove.first, AIMove.second);
			Player = 1;
			if (NewView)
			{
				delete this->View;
				this->View = NewView;
				NewView = nullptr;
			}
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
	this->IO->Display(this->Field);
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
