/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.class.Base.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:45:13 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 17:15:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main/AI.class.hpp"

std::pair<size_t, size_t>	Engine::AI::MakeMove(
								char Player,
								std::vector<std::vector<char>> const &Field)
{
	std::vector<std::vector<char>>		FieldTmp = Field;
	char								Enemy;
	std::pair<size_t, size_t>			Move;

	if (Player == 1)
		Enemy = 2;
	else
		Enemy = 1;
	if (TryToWinInOneMove(Player, FieldTmp, Move))
		return (Move);
	if (TryToWinInOneMove(Enemy, FieldTmp, Move))
		return (Move);
	if (TryToWinInTwoMoves(Player, FieldTmp, Move))
		return (Move);
	if (TryToWinInTwoMoves(Enemy, FieldTmp, Move))
		return (Move);
	return (this->RandomMove(FieldTmp));
}

bool		Engine::AI::TryToWinInOneMove(
								char Player,
								std::vector<std::vector<char>> &Field,
								std::pair<size_t, size_t> &Move)
{
	for (size_t i = 0; i < Field.size(); i++)
		for (size_t j = 0; j < Field.size(); j++)
			if (Field[i][j] == 0)
			{
				Field[i][j] = Player;
				if (this->Eng->CheckWin(Field))
				{
					Field[i][j] = 0;
					Move.first = i;
					Move.second = j;
					return (true);
				}
				Field[i][j] = 0;
			}
	return (false);
}

bool		Engine::AI::TryToWinInTwoMoves(
								char Player,
								std::vector<std::vector<char>> &Field,
								std::pair<size_t, size_t> &Move)
{
	for (size_t i = 0; i < Field.size(); i++)
		for (size_t j = 0; j < Field.size(); j++)
			if (Field[i][j] == 0)
			{
				Field[i][j] = Player;
				if (this->CheckForWinInTwoMoves(Player, Field))
				{
					Field[i][j] = 0;
					Move.first = i;
					Move.second = j;
					return (true);
				}
				Field[i][j] = 0;
			}
	return (false);
}

bool						Engine::AI::CheckForWinInTwoMoves(
								char Player,
								std::vector<std::vector<char>> &Field)
{
	int		ct;

	ct = 0;
	for (size_t i = 0; i < Field.size(); i++)
		for (size_t j = 0; j < Field.size(); j++)
			if (Field[i][j] == 0)
			{
				Field[i][j] = Player;
				if (this->Eng->CheckWin(Field))
					ct++;
				Field[i][j] = 0;
			}
	if (ct >= 2)
		return (true);
	else
		return (false);
}

std::pair<size_t, size_t>	Engine::AI::RandomMove(
								std::vector<std::vector<char>> &Field)
{
	if (Field[1][1] == 0)
		return (std::pair<size_t, size_t>(1, 1));
	if (Field[0][0] == 0)
		return (std::pair<size_t, size_t>(0, 0));
	if (Field[0][2] == 0)
		return (std::pair<size_t, size_t>(0, 2));
	if (Field[2][2] == 0)
		return (std::pair<size_t, size_t>(2, 2));
	if (Field[2][0] == 0)
		return (std::pair<size_t, size_t>(2, 0));
	for (size_t i = 0; i < Field.size(); i++)
		for (size_t j = 0; j < Field.size(); j++)
			if (Field[i][j] == 0)
				return (std::pair<size_t, size_t>(i, j));
	throw std::runtime_error("I can make move!");
}
