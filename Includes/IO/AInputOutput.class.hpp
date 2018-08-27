/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInputOutput.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:17:38 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 15:48:35 by adzikovs         ###   ########.fr       */
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

	virtual void				Display(std::vector<std::vector<char>> const &Field) = 0;
	virtual void				AddErrorMsg(std::string const &Msg) = 0;
	virtual void				ClearErrorMsgs(void) = 0;

public:
								AInputOutput(void);
								AInputOutput(AInputOutput const &Src);
	virtual						~AInputOutput(void);
	AInputOutput				&operator=(AInputOutput const &Rhs);
};
