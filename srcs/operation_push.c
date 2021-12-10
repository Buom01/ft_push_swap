/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:24:33 by badam             #+#    #+#             */
/*   Updated: 2021/12/11 00:13:04 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **to, t_list **from)
{
	t_list	*elem;

	if (ft_lstsize(*from) < 1)
		return ;
	elem = *from;
	*from = (*from)->next;
	elem->next = *to;
	*to = elem;
}

void	pa(t_list **a, t_list **b, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("pa\n", 1);
	push(a, b);
	++(cfg->operations);
}

void	pb(t_list **b, t_list **a, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("pb\n", 1);
	push(b, a);
	++(cfg->operations);
}

void	auto_push(t_list **list, t_list **a, t_list **b, t_config *cfg)
{
	if (list == a)
		pa(a, b, cfg);
	else
		pb(b, a, cfg);
}
