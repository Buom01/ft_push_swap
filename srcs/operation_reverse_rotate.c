/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:55 by badam             #+#    #+#             */
/*   Updated: 2021/12/11 00:14:04 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **list)
{
	t_list	*elem;

	if (is_empty(*list))
		return ;
	elem = ft_lstlast(*list);
	elem->next = *list;
	*list = elem;
	while (elem->next != *list)
	{
		elem = elem->next;
	}
	elem->next = NULL;
}

void	rra(t_list **a, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("rra\n", 1);
	reverse_rotate(a);
	++(cfg->operations);
}

void	rrb(t_list **b, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("rrb\n", 1);
	reverse_rotate(b);
	++(cfg->operations);
}

void	rrr(t_list **a, t_list **b, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("rrr\n", 1);
	reverse_rotate(a);
	reverse_rotate(b);
	++(cfg->operations);
}

void	auto_reverse_rotate(t_list **list, t_list **a, t_list **b,
			t_config *cfg)
{
	if (list == a)
		rra(a, cfg);
	else
		rrb(b, cfg);
}
