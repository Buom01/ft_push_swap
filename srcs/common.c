/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:13 by badam             #+#    #+#             */
/*   Updated: 2021/12/12 15:37:38 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	get_first_number(char ***argv, bool *error)
{
	while (***argv && ft_isspace(***argv))
		++**argv;
	if (!(ft_isdigit(***argv) || ***argv == '-' || ***argv == '+'))
		*error = true;
	return (*error);
}

bool	get_next_number(char ***argv, int *argc, bool *error)
{
	if (*error)
		return (error);
	if (***argv == '-' || ***argv == '+')
		++**argv;
	if (!ft_isdigit(***argv))
		*error = true;
	while (ft_isdigit(***argv))
		++**argv;
	while (ft_isspace(***argv))
		++**argv;
	if (!***argv)
	{
		++**argv;
		if (!--*argc)
			return (*error);
	}
	return (get_first_number(argv, error));
}
