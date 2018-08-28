/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChengeOutputModeView.class.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:32:14 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 15:32:14 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Views/AView.class.hpp"

class							Engine::ChangeOutputModeView : public Engine::AView
{
public:
	size_t						Execute(std::string const &Input) override;
	void						Display(void) override;

public:
								ChangeOutputModeView(Engine &Eng) : AView(Eng) {}
								~ChangeOutputModeView(void) {}

private:
								ChangeOutputModeView(void);
								ChangeOutputModeView(ChangeOutputModeView const &Src);
	ChangeOutputModeView		&operator=(ChangeOutputModeView const &Rhs);
};
