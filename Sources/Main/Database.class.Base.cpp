/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.class.Base.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:25:44 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 10:40:16 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "Main/Database.class.hpp"

void									Database::Set(char Player,
											size_t y, size_t x)
{
	if (x >= this->Field.size() || y >= this->Field.size())
		throw Database::PositionOutOfRangeError(y, x);
	if (this->Field[y][x] != 0)
		throw Database::PositionOccupiedError(y, x);
	this->Field[y][x] = Player;
}

std::vector<std::vector<char>> const	&Database::Get(void) const
{
	return (this->Field);
}

bool Database::FreeSpaceExists() const
{
	for (size_t i = 0; i < this->Field.size(); i++)
		if (std::find(this->Field[i].begin(), this->Field[i].end(), 0) != this->Field[i].end())
			return (true);
	return (false);
}
