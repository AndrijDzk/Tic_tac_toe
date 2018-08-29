/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Base.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:20:07 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:41:54 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Main/Engine.class.hpp"
#include "Views/AView.class.hpp"

int		Engine::Run(void)
{
	std::string					Command;
	bool						Run = true;
	size_t						NewView;

	this->IO->Init();
	while (Run)
	{
		this->Views[CurrView]->Display();
		this->IO->ClearErrorMsgs();
		try
		{
			Command = this->IO->ReadInput();
			NewView = this->Views[CurrView]->Execute(Command);
			if (NewView != this->CurrView)
			{
				this->PrevView = this->CurrView;
				this->CurrView = NewView;
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
		catch (Engine::Exit &e)
		{
			this->IO->DeInit();
			return (0);
		}
	}
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

void	Engine::ClearField(void)
{
	for (size_t i = 0; i < this->Field.size(); i++)
		for (size_t j = 0; j < this->Field[i].size(); j++)
			Field[i][j] = 0;
}

bool	Engine::FreeSpaceExists(void) const
{
	for (size_t i = 0; i < this->Field.size(); i++)
		if (std::find(this->Field[i].begin(), this->Field[i].end(), 0) != this->Field[i].end())
			return (true);
	return (false);
}

void	Engine::ChangeOutputMode(AIOFactory::e_IO_type NewIO)
{
	AInputOutput*		Prev;
	AInputOutput*		New;

	if (NewIO != this->CurrIOMode)
	{
		try
		{
			New = AIOFactory::CreateNewIO(NewIO);
			Prev = this->IO;
			Prev->DeInit();
			New->Init();
			delete Prev;
			this->IO = New;
			this->CurrIOMode = NewIO;
		}
		catch (AIOFactory::UnhandledIOError &e) {}
		catch (AInputOutput::DeInitError &e) { delete New;}
		catch (AInputOutput::InitError &e)
		{
			delete New;
			Prev->Init();
		}
	}
}

void	Engine::ChangePlayer(void)
{
	if (this->CurrPlayer == 1)
		this->CurrPlayer = 2;
	else
		this->CurrPlayer = 1;
}

bool	Engine::CheckGameOver(void)
{
	if (this->CheckWin(this->Field))
		return (true);
	if (this->FreeSpaceExists() == false)
	{
		this->CurrPlayer = 0;
		return (true);
	}
	return (false);
}
