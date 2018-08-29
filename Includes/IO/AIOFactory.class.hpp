/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AIOFactory.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:50:15 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 13:15:21 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "IO/AInputOutput.class.hpp"

class						AIOFactory
{
private:
	typedef AInputOutput*					(AIOFactory::*t_FM)(void);

public:
	enum 									e_IO_type {Console = 0, ncurses = 1};
	class									UnhandledIOError : public std::runtime_error {public: UnhandledIOError(void) : std::runtime_error("AIOFactory: Unhandled IO type!") {}};
	static AInputOutput*					CreateNewIO(e_IO_type Type);

private:
	static AIOFactory*						Singleton;
	AInputOutput*							_CreateNewIO(e_IO_type Type);
	AInputOutput*							CreateConsoleIO(void);
	AInputOutput*							Create_ncursesIO(void);
	std::vector<AIOFactory::t_FM>			FactoryMethods;
	std::vector<AIOFactory::e_IO_type>		FM_IDs;

private:
											AIOFactory(void);
											AIOFactory(AIOFactory const &Src);
											~AIOFactory(void);
	AIOFactory								&operator=(AIOFactory const &Rhs);
};
