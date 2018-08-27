/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:09:10 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 10:25:15 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "IO/AInputOutput.class.hpp"

class										Database
{
public:
	void									Set(char Player, size_t y, size_t x);
	std::vector<std::vector<char>> const	&Get(void) const;
	bool									FreeSpaceExists(void) const;

public:
	class PositionOutOfRangeError : public std::logic_error {public: PositionOutOfRangeError(size_t y, size_t x) : std::logic_error("Position out of range: " + std::to_string(y) + " " + std::to_string(x)) {}};
	class PositionOccupiedError : public std::logic_error {public: PositionOccupiedError(size_t y, size_t x) : std::logic_error("Position occupied: " + std::to_string(y) + " " + std::to_string(x)) {}};

private:
	std::vector<std::vector<char>>			Field;

public:
											Database(size_t Size);
											~Database(void);

private:
											Database(void);
											Database(Database const &Src);
	Database								&operator=(Database const &Rhs);
};
