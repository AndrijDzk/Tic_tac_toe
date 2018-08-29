/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AIOFactory.class.Coplien.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:09:07 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 13:09:07 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IO/AIOFactory.class.hpp"

#include "IO/ConsoleIO.class.hpp"
#include "IO/ncursesIO.class.hpp"

AIOFactory::AIOFactory(void)
{
	this->FM_IDs.push_back(AIOFactory::Console);
	this->FactoryMethods.push_back(&AIOFactory::CreateConsoleIO);

	this->FM_IDs.push_back(AIOFactory::ncurses);
	this->FactoryMethods.push_back(&AIOFactory::Create_ncursesIO);
}

AIOFactory::~AIOFactory(void) {}
