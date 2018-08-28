/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.class.CheckWin.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:47:48 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 17:34:09 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "Main/Engine.class.hpp"

bool		Engine::CheckWin(t_Field const &Field) const
{
	for (size_t i = 0; i < Field.size(); i++)
	{
		if (this->CheckRow(Field, i))
			return (true);
		else if (this->CheckColumn(Field, i))
			return (true);
	}
	if (this->CheckDiagonal(Field, 0, 1))
		return (true);
	else if (this->CheckDiagonal(Field, Field.size() - 1, -1))
		return (true);
	else
		return (false);
}

bool		Engine::CheckRow(t_Field const &Field, size_t n) const
{
	for (size_t i = 1; i < Field[n].size(); i++)
		if (Field[n][i] == 0 || Field[n][i] != Field[n][i - 1])
			return (false);
	return (true);
}

bool		Engine::CheckColumn(t_Field const &Field, size_t n) const
{
	for (size_t i = 1; i < Field.size(); i++)
		if (Field[i][n] == 0 || Field[i][n] != Field[i - 1][n])
			return (false);
	return (true);
}

bool		Engine::CheckDiagonal(t_Field const &Field, size_t start, int inc) const
{
	size_t		x;
	size_t		y;

	y = start + inc;
	x = 1;
	while (x < Field.size())
	{
		if (Field[y][x] == 0 || Field[y][x] != Field[y - inc][x - 1])
			return (false);
		x++;
		y += inc;
	}
	return (true);
}
