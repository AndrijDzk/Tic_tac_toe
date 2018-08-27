/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:08:33 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 16:41:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IO/AInputOutput.class.hpp"
#include "Main/Database.class.hpp"

class				AView;

class WrongInputError : public std::logic_error {public: WrongInputError(std::string const &Input) : std::logic_error("Wrong Input: " + Input) {}};

class 				Engine
{
public:
	int				Run(void);
	void			Put(char Player, size_t y, size_t x);

private:
	bool			CheckWin(std::vector<std::vector<char>> const &Field) const;
	bool			CheckRow(std::vector<std::vector<char>> const &Field, size_t n) const;
	bool			CheckColumn(std::vector<std::vector<char>> const &Field, size_t n) const;
	bool			CheckDiagonal(std::vector<std::vector<char>> const &Field, size_t start, int inc) const;
	AInputOutput*	IO;
	Database		DB;
	AView*			View;
	class			AI;
	AI*				Skynet;

public:
					Engine(void);
					~Engine(void);

private:
					Engine(Engine const &Src);
	Engine			&operator=(Engine const &Rhs);
};
