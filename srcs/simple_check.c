/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:07 by badam             #+#    #+#             */
/*   Updated: 2021/12/08 17:55:31 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	exec_line(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "SA"))
		sa(a, true);
	else if (!ft_strcmp(line, "SB"))
		sb(b, true);
	else if (!ft_strcmp(line, "SS"))
		ss(a, b, true);
	else if (!ft_strcmp(line, "PA"))
		pa(a, b, true);
	else if (!ft_strcmp(line, "PB"))
		pb(b, a, true);
	else if (!ft_strcmp(line, "RA"))
		ra(a, true);
	else if (!ft_strcmp(line, "RB"))
		rb(b, true);
	else if (!ft_strcmp(line, "RR"))
		rr(a, b, true);
	else if (!ft_strcmp(line, "RRA"))
		rra(a, true);
	else if (!ft_strcmp(line, "RRB"))
		rrb(b, true);
	else if (!ft_strcmp(line, "RRR"))
		rrr(a, b, true);
	else
		return (false);
	return (true);
}

void	check(t_list **a, t_list **b)
{
	char	*line;
	bool	error;

	error = false;
	while (!error && get_next_line(0, &line) > 0)
	{
		if (!exec_line(line, a, b))
		{
			error = true;
			handle_error(a, b);
		}
		free(line);
	}
	if (!error)
	{
		if (ft_lstsize(*b) == 0 && is_sorted(*a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
}
