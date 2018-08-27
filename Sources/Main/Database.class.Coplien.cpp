/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.class.Coplien.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:15:42 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 10:16:35 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main/Database.class.hpp"

Database::Database(size_t Size) : Field(Size, std::vector<char>(Size, 0)) {}

Database::~Database(void) {}
