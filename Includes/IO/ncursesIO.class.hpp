/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesIO.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:53:32 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 14:23:16 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define NCURSES_ON
#ifdef NCURSES_ON

#include <vector>
#include <string>
#include <ncurses.h>

#include "IO/AInputOutput.class.hpp"

class								ncursesIO : public AInputOutput
{
public:
	void							Init(void) override;
	void							DeInit(void) override;
	std::string						ReadInput(void) override;

	void							Display(std::vector<std::vector<char>> const &Field) override;
	void							AddErrorMsg(std::string const &Msg) override;
	void							ClearErrorMsgs(void) override;

private:
	std::vector<std::string>		ErrorMsgs;

public:
	class WindowTooSmallError : public std::logic_error {public: WindowTooSmallError(int y, int x) : std::logic_error("Window too small: " + std::to_string(y) + " " + std::to_string(x)) {}};

public:
									ncursesIO(void);
									~ncursesIO(void) override;

private:
									ncursesIO(ncursesIO const &Src);
	ncursesIO						&operator=(ncursesIO const &Rhs);
};

#endif
