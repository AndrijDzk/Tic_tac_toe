/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOutput.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:25:15 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/25 17:25:15 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class				AOutput
{
public:
	virtual void	Init(void) = 0;
	virtual void	DeInit(void) = 0;

	virtual void	Display(void) = 0;
	virtual void	Update(void) = 0;
};
