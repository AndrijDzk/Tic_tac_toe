/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:08:33 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 11:11:02 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "IO/AInputOutput.class.hpp"

class				AView;

class WrongInputError : public std::logic_error {public: WrongInputError(std::string const &Input) : std::logic_error("Wrong Input: " + Input) {}};

typedef std::vector<std::vector<char>>		t_Field;

class 				Engine
{
public:

public:
	int				Run(void);
	void			Set(char Player, size_t y, size_t x);

private:
	bool			CheckWin(t_Field const &Field) const;
	bool			CheckRow(t_Field const &Field, size_t n) const;
	bool			CheckColumn(t_Field const &Field, size_t n) const;
	bool			CheckDiagonal(t_Field const &Field, size_t start, int inc) const;
	bool			FreeSpaceExists(void) const;
	AInputOutput*	IO;
	t_Field			Field;
	AView*			View;
	class			AI;
	AI*				Skynet;

public:
	class PositionOutOfRangeError : public std::logic_error {public: PositionOutOfRangeError(size_t y, size_t x) : std::logic_error("Position out of range: " + std::to_string(y) + " " + std::to_string(x)) {}};
	class PositionOccupiedError : public std::logic_error {public: PositionOccupiedError(size_t y, size_t x) : std::logic_error("Position occupied: " + std::to_string(y) + " " + std::to_string(x)) {}};

public:
					Engine(void);
					~Engine(void);

private:
					Engine(Engine const &Src);
	Engine			&operator=(Engine const &Rhs);
};
