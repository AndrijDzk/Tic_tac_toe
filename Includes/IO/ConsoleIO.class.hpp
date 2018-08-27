/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConsoleIO.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:34:39 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 15:32:43 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>


#include "AInputOutput.class.hpp"

class								ConsoleIO : public AInputOutput
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
									ConsoleIO(void);
									~ConsoleIO(void) override;

private:
									ConsoleIO(ConsoleIO const &Src);
	ConsoleIO						&operator=(ConsoleIO const &Rhs);
};
