/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Coplien.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:11:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 13:59:05 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main/Defines.hpp"
#include "Main/Engine.class.hpp"
#include "IO/ConsoleIO.class.hpp"
#include "IO/ncursesIO.class.hpp"
#include "Views/StartMenuView.class.hpp"
#include "Views/GameView.class.hpp"
#include "Views/GameMenuView.class.hpp"
#include "Views/ChengeOutputModeView.class.hpp"
#include "Views/GameOverView.class.hpp"
#include "Main/AI.class.hpp"

Engine::Engine(void) :
		Players(Engine::OnePlayer),
		CurrPlayer(1),
		Field(3, std::vector<char>(3, 0)),
		PrevView(START_MENU_VIEW),
		CurrView(START_MENU_VIEW),
		CurrIOMode(AIOFactory::Console),
		IO(new ConsoleIO),
		Views(std::vector<AView*>()),
		Skynet(new AI(this))
{
	this->Views.push_back(new StartMenuView(*this));
	this->Views.push_back(new GameView(*this));
	this->Views.push_back(new GameMenuView(*this));
	this->Views.push_back(new ChangeOutputModeView(*this));
	this->Views.push_back(new GameOverView(*this));
}

Engine::~Engine(void)
{
	size_t		i;
	if (this->IO)
	{
		this->IO->DeInit();
		delete this->IO;
		this->IO = nullptr;
	}
	if (this->Skynet)
	{
		delete this->Skynet;
		this->Skynet = nullptr;
	}
	i = this->Views.size();
	while (i > 0)
	{
		i--;
		delete (this->Views[i]);
		this->Views.pop_back();
	}
}
