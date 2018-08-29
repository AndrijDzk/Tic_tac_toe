/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:05:38 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/29 15:05:31 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Main/Engine.class.hpp"

#include "Main/AI.class.hpp"

int		main(void)
{
	Engine		Eng;

	try
	{
		Eng.Run();
	}
	catch (std::exception &e)
	{
		std::cout << "Uncaught exception: " << e.what() << std::endl;
	}
	return (0);
}
