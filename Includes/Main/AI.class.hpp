/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:30:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 17:15:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Main/Engine.class.hpp"

class								Engine::AI
{
public:
	class NotPossibleError : public std::exception {};
public:
	std::pair<size_t, size_t>		MakeMove(char Player, std::vector<std::vector<char>> const &Field);

private:
	bool							TryToWinInOneMove(char Player, std::vector<std::vector<char>> &Field, std::pair<size_t, size_t> &Move);
	bool							TryToWinInTwoMoves(char Player, std::vector<std::vector<char>> &Field, std::pair<size_t, size_t> &Move);
	bool							CheckForWinInTwoMoves(char Player, std::vector<std::vector<char>> &Field);
	std::pair<size_t, size_t>		RandomMove(std::vector<std::vector<char>> &Field);
	Engine*							Eng;

public:
									AI(Engine* Eng) : Eng(Eng) {}
									~AI(void) {}
private:
									AI(void);
									AI(AI const &Src);
	AI								&operator=(AI const &Rhs);
};
