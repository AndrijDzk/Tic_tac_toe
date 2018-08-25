/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInput.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:17:38 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/25 17:17:38 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>

class							AInput
{
public:

	typedef struct				InputCommand
	{
		unsigned	x;
		unsigned	y;
	}							t_InputCommand;

	virtual t_InputCommand		ReadInput(void) = 0;

	virtual void				Init(void) = 0;
	virtual void				DeInit(void) = 0;
};
