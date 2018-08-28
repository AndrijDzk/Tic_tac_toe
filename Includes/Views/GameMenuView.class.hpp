/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameMenuView.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:27:20 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/28 13:33:46 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AView.class.hpp"

class					Engine::GameMenuView : public Engine::AView
{
public:
	size_t				Execute(std::string const &Inut) override;
	void				Display(void) override;

public:
						GameMenuView(Engine &Eng) : AView(Eng) {}
						~GameMenuView(void) {}

private:
						GameMenuView(void);
						GameMenuView(GameMenuView const &Src);
	GameMenuView		&operator=(GameMenuView const &Rhs);
};
