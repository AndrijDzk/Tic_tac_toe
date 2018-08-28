/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AView.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:51:00 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 14:13:51 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Main/Engine.class.hpp"

class					Engine::AView
{
public:
	virtual size_t		Execute(std::string const &Input) = 0;
	virtual void		Display(void) = 0;

protected:
	Engine				&Eng;

public:
						AView(Engine &Eng) : Eng(Eng) {}
	virtual				~AView(void) {};

private:
						AView(void);
						AView(AView const &Src);
	AView				&operator=(AView const &Rhs);
};
