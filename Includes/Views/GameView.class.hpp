/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameView.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:56:00 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 14:02:35 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AView.class.hpp"

class			Engine::GameView : public Engine::AView
{
public:
	size_t		Execute(std::string const &Input) override;
	void		Display(void) override;

public:
				GameView(Engine &Eng) : AView(Eng) {}
				~GameView(void) {}

private:
				GameView(void);
				GameView(GameView const &Src);
	GameView	&operator=(GameView const &Rhs);
};
