/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.class.Base.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:45:13 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:54:47 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>

#include "Main/AI.class.hpp"

t_Point		Engine::AI::MakeMove(char Player, t_Field const &Field)
{
	t_Field		FieldTmp = Field;
	char								Enemy;
	t_Point			Move;

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
	return (this->RandomMove(Player,FieldTmp));
}

bool		Engine::AI::TryToWinInOneMove(char Player, t_Field &Field, t_Point &Move)
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

bool		Engine::AI::TryToWinInTwoMoves(char Player, t_Field &Field, t_Point &Move)
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

bool		Engine::AI::CheckForWinInTwoMoves(char Player, t_Field &Field)
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

t_Point		Engine::AI::RandomMove(char Player, t_Field &Field)
{
	if (Field[1][1] == 0)
		return (t_Point(1, 1));
	if (Field[0][0] == 0)
		return (t_Point(0, 0));
	if (Field[0][2] == 0)
		return (t_Point(0, 2));
	if (Field[2][2] == 0)
		return (t_Point(2, 2));
	if (Field[2][0] == 0)
		return (t_Point(2, 0));
	return (this->BFS(Player, Field));
}

t_Point		Engine::AI::BFS(char Player, t_Field &Field)
{
	std::queue<std::vector<size_t>>		Stack;
	std::vector<size_t>					Front;
	std::vector<t_Point>				FreePositions;

	for (size_t i = 0; i < Field.size(); i++)
		for (size_t j = 0; j < Field.size(); j++)
			if (Field[i][j] == 0)
			{
				FreePositions.push_back(t_Point(i, j));
				Stack.push(std::vector<size_t>(1, FreePositions.size() - 1));
			}
	if (FreePositions.empty())
		throw std::runtime_error("AI; I cant make move - there no free space left!");
	while (Stack.empty() == false)
	{
		Front = Stack.front();
		Stack.pop();
		if (this->PathCompleted(Player, Field, FreePositions, Front))
			return (FreePositions[Front[0]]);
		if (Front.size() < FreePositions.size())
			for (size_t i = 0; i < FreePositions.size(); i++)
				if (std::find(Front.begin(), Front.end(), i) == Front.end())
				{
					Front.push_back(i);
					Stack.push(Front);
					Front.pop_back();
				}
	}
	return (FreePositions[0]);
}

bool		Engine::AI::PathCompleted(
				char Player,
				t_Field &Field,
				std::vector<t_Point> const &Points,
				std::vector<size_t> const &Path)
{
	size_t		y;
	size_t		x;
	bool		Res;

	for (size_t i = 0; i < Path.size(); i++)
	{
		y = Points[Path[i]].first;
		x = Points[Path[i]].second;
		if (Field[y][x] != 0)
			throw std::runtime_error("AI: Trying to set an occupied position!");
		Field[y][x] = Player;
	}
	if (this->Eng->CheckWin(Field))
		Res = true;
	else
		Res = false;
	for (size_t i = 0; i < Path.size(); i++)
	{
		y = Points[Path[i]].first;
		x = Points[Path[i]].second;
		Field[y][x] = 0;
	}
	return (Res);
}
