/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AIOFactory.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:16:18 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 13:16:18 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IO/AIOFactory.class.hpp"

#include "IO/ConsoleIO.class.hpp"
#include "IO/ncursesIO.class.hpp"

AIOFactory*			AIOFactory::Singleton = nullptr;

AInputOutput*		AIOFactory::CreateNewIO(e_IO_type Type)
{
	if (AIOFactory::Singleton == nullptr)
		AIOFactory::Singleton = new AIOFactory();
	return (AIOFactory::Singleton->_CreateNewIO(Type));
}

AInputOutput*		AIOFactory::_CreateNewIO(e_IO_type Type)
{
	for (size_t i = 0; i < this->FM_IDs.size() && i < this->FactoryMethods.size(); i++)
		if (Type == this->FM_IDs[i])
			return ((this->*(this->FactoryMethods[i]))());
	throw AIOFactory::UnhandledIOError();
}

AInputOutput*		AIOFactory::CreateConsoleIO(void)
{
	return (new ConsoleIO);
}

AInputOutput*		AIOFactory::Create_ncursesIO(void)
{
#ifdef NCURSES_ON
	return (new ncursesIO);
#else
	throw AIOFactory::UnhandledIOError();
#endif
}
