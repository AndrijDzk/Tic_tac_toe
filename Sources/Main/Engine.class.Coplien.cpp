/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Coplien.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:11:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 15:08:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main/Engine.class.hpp"
#include "IO/ConsoleIO.class.hpp"
#include "IO/ncursesIO.class.hpp"
#include "Views/StartMenuView.class.hpp"
#include "Views/GameView.class.hpp"
#include "Views/GameMenuView.class.hpp"
#include "Main/AI.class.hpp"

Engine::Engine(void) :
		Field(3, std::vector<char>(3, 0)),
		CurrView(0),
		IO(new ConsoleIO),
		Views(std::vector<AView*>()),
		Skynet(new AI(this))
{
	this->Views.push_back(new StartMenuView(*this));
	this->Views.push_back(new GameView(*this));
	this->Views.push_back(new GameMenuView(*this));
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
