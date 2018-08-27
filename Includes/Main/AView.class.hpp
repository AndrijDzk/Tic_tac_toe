/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AView.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:51:00 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 15:56:57 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Main/Engine.class.hpp"

class					AView
{
public:
	virtual AView*		Execute(std::string const &Input, char Player) = 0;

protected:
	Engine				&_Engine;

public:
						AView(Engine &Eng) : _Engine(Eng) {}
	virtual				~AView(void) {};

private:
						AView(void);
						AView(AView const &Src);
	AView				&operator=(AView const &Rhs);
};
