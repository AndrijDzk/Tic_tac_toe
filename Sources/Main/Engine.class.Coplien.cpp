/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.Coplien.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:11:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 16:20:21 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main/Engine.class.hpp"
#include "IO/ConsoleIO.class.hpp"
#include "IO/ncursesIO.class.hpp"
#include "Main/GameView.class.hpp"
#include "Main/AI.class.hpp"

Engine::Engine(void) :
	IO(new ConsoleIO),
	DB(3),
	View(new GameView(*this)),
	Skynet(new AI(this)) {}

Engine::~Engine(void)
{
	if (this->IO)
	{
		this->IO->DeInit();
		delete this->IO;
		this->IO = nullptr;
	}
	if (this->View)
	{
		delete this->View;
		this->View = nullptr;
	}
	if (this->Skynet)
	{
		delete this->Skynet;
		this->Skynet = nullptr;
	}
}
