/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:30:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 12:17:14 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Main/Engine.class.hpp"

typedef std::pair<size_t, size_t>	t_Point;

class								Engine::AI
{
public:
	class NotPossibleError : public std::exception {};
public:
	t_Point			MakeMove(char Player, t_Field const &Field);

private:
	bool			TryToWinInOneMove(char Player, t_Field &Field, t_Point &Move);
	bool			TryToWinInTwoMoves(char Player, t_Field &Field, t_Point &Move);
	bool			CheckForWinInTwoMoves(char Player, t_Field &Field);
	t_Point			RandomMove(char Player, t_Field &Field);
	t_Point			BFS(char Player, t_Field &Field);
	bool			PathCompleted(char Player, t_Field &Field, std::vector<t_Point> const &Points, std::vector<size_t> const &Path);
	Engine*			Eng;

public:
					AI(Engine* Eng) : Eng(Eng) {}
					~AI(void) {}
private:
					AI(void);
					AI(AI const &Src);
	AI				&operator=(AI const &Rhs);
};
