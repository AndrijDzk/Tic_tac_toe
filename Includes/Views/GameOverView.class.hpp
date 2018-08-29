/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameOverView.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:22:31 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 14:22:31 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Views/AView.class.hpp"

class					Engine::GameOverView : public Engine::AView
{
public:
	size_t				Execute(std::string const &Input) override;
	void				Display(void) override;

public:
						GameOverView(Engine &Eng) : AView(Eng) {}
						~GameOverView(void) {}

private:
						GameOverView(void);
						GameOverView(GameOverView const &src);
	GameOverView		&operator=(GameOverView const &Rhs);
};
