/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:08:33 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 15:05:31 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "IO/AIOFactory.class.hpp"

class WrongInputError : public std::logic_error {public: WrongInputError(void) : std::logic_error("Wrong Input") {}};

typedef std::vector<std::vector<char>>		t_Field;

class 						Engine
{
public:
	int						Run(void);

private:
	class					AI;
	class					AView;
	class					StartMenuView;
	class					GameView;
	class					GameMenuView;
	class					ChangeOutputModeView;
	class					GameOverView;
	enum					e_Players_AM {OnePlayer = 1, TwoPlayers = 2};

private:
	void					Set(char Player, size_t y, size_t x);
	void 					ClearField(void);
	bool					CheckGameOver(void);
	bool					CheckWin(t_Field const &Field) const;
	bool					CheckRow(t_Field const &Field, size_t n) const;
	bool					CheckColumn(t_Field const &Field, size_t n) const;
	bool					CheckDiagonal(t_Field const &Field, size_t start, int inc) const;
	bool					FreeSpaceExists(void) const;
	void					ChangeOutputMode(AIOFactory::e_IO_type NewIO);
	void					ChangePlayer(void);
	e_Players_AM			Players;
	char					CurrPlayer;
	t_Field					Field;
	size_t					PrevView;
	size_t					CurrView;
	AIOFactory::e_IO_type	CurrIOMode;
	AInputOutput*			IO;
	std::vector<AView*>		Views;
	AI*						Skynet;

public:
	class PositionOutOfRangeError : public std::logic_error {public: PositionOutOfRangeError(size_t y, size_t x) : std::logic_error("Position out of range: " + std::to_string(y) + " " + std::to_string(x)) {}};
	class PositionOccupiedError : public std::logic_error {public: PositionOccupiedError(size_t y, size_t x) : std::logic_error("Position occupied: " + std::to_string(y) + " " + std::to_string(x)) {}};
	class Exit : public std::logic_error {public: Exit(void) : std::logic_error("Exit") {}};

public:
							Engine(void);
							~Engine(void);

private:
							Engine(Engine const &Src);
	Engine					&operator=(Engine const &Rhs);
};
