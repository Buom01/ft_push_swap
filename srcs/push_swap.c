/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:57:28 by badam             #+#    #+#             */
/*   Updated: 2021/12/05 23:57:48 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	get_first_number(char ***argv, bool *error)
{
	while (***argv && ft_isspace(***argv))
		++**argv;
	if (!(ft_isdigit(***argv) || ***argv == '-'))
		*error = true;
	return (*error);
}

static bool	get_next_number(char ***argv, int *argc, bool *error)
{
	if (*error)
		return (error);
	while (ft_isdigit(***argv) || ***argv == '-')
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

void	freeup(t_list **a, t_list **b)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
}

int	main(int argc, char **argv)
{
	bool	error;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	error = false;
	--argc;
	++argv;
	get_first_number(&argv, &error);
	while (!error && argc)
	{
		new_appended_elem(ft_atoi(*argv), &a, &error);
		get_next_number(&argv, &argc, &error);
	}
	if (error)
		return (handle_error(&a, &b));
	simple_sort(&a, &b);
	freeup(&a, &b);
	return (0);
}
