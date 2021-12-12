/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:07 by badam             #+#    #+#             */
/*   Updated: 2021/12/12 15:31:20 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	exec_line(char *line, t_list **a, t_list **b, t_config *cfg)
{
	if (!ft_strcmp(line, "sa"))
		sa(a, cfg);
	else if (!ft_strcmp(line, "sb"))
		sb(b, cfg);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b, cfg);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b, cfg);
	else if (!ft_strcmp(line, "pb"))
		pb(b, a, cfg);
	else if (!ft_strcmp(line, "ra"))
		ra(a, cfg);
	else if (!ft_strcmp(line, "rb"))
		rb(b, cfg);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b, cfg);
	else if (!ft_strcmp(line, "rra"))
		rra(a, cfg);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b, cfg);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b, cfg);
	else
		return (false);
	return (cfg);
}

void	check(t_list **a, t_list **b, t_config *cfg)
{
	char	*line;

	while (!cfg->error && get_next_line(0, &line) > 0)
	{
		if (*line == '\n' && !*(line + 1))
			break ;
		if (!exec_line(line, a, b, cfg))
		{
			cfg->error = true;
			handle_error(a, b, cfg);
		}
		free(line);
	}
	if (line)
		free(line);
	if (!cfg->error)
	{
		if (ft_lstsize(*b) == 0 && is_sorted(*a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
}
