/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameView.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:56:00 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 15:56:57 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Main/AView.class.hpp"

class			GameView : public AView
{
public:
	AView*		Execute(std::string const &Input, char Player) override;

public:
				GameView(Engine &Eng) : AView(Eng) {}
				~GameView(void) {}

private:
				GameView(void);
				GameView(GameView const &Src);
	GameView	&operator=(GameView const &Rhs);
};
