/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Base.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:20:07 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 17:21:14 by adzikovs         ###   ########.fr       */
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
	while (this->DB.FreeSpaceExists() && !this->CheckWin(this->DB.Get()))
	{
		this->IO->Display(this->DB.Get());
		this->IO->ClearErrorMsgs();
		try
		{
			Command = this->IO->ReadInput();
			NewView = this->View->Execute(Command, Player);
			Player = 2;
			AIMove = this->Skynet->MakeMove(Player, this->DB.Get());
			this->DB.Set(Player, AIMove.first, AIMove.second);
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
		catch (Database::PositionOutOfRangeError &e)
		{
			this->IO->AddErrorMsg(e.what());
		}
		catch (Database::PositionOccupiedError &e)
		{
			this->IO->AddErrorMsg(e.what());
		}
	}
	this->IO->Display(this->DB.Get());
	return (0);
}

void	Engine::Put(char Player, size_t y, size_t x)
{
	this->DB.Set(Player, y, x);
}
