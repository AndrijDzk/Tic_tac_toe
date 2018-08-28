/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartMenuView.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:30:40 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 14:30:40 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Views/AView.class.hpp"

class				Engine::StartMenuView : public Engine::AView
{
public:
	size_t			Execute(std::string const &Input) override;
	void			Display(void) override;

public:
					StartMenuView(Engine &Eng) : AView(Eng) {}
					~StartMenuView(void) {};

private:
					StartMenuView(void);
					StartMenuView(StartMenuView const &Src);
	StartMenuView	&operator=(StartMenuView const &Rhs);
};
