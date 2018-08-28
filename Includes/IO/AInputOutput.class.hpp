/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInputOutput.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:17:38 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 14:08:30 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <utility>
#include <stdexcept>

class							AInputOutput
{
public:
	virtual void				Init(void) = 0;
	virtual void				DeInit(void) = 0;
	virtual std::string			ReadInput(void) = 0;

	virtual void				DisplayGame(std::vector<std::vector<char>> const &Field) = 0;
	virtual void				DisplayGameMenu(void) = 0;
	virtual void				DisplayStartMenu(void) = 0;
	virtual void				DisplayChangeOutputMenu(void) = 0;

	virtual void				AddErrorMsg(std::string const &Msg) = 0;
	virtual void				ClearErrorMsgs(void) = 0;

public:
								AInputOutput(void) {};
								AInputOutput(AInputOutput const &Src);
	virtual						~AInputOutput(void) {};
	AInputOutput				&operator=(AInputOutput const &Rhs);
};
