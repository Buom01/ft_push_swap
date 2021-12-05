/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:24:33 by badam             #+#    #+#             */
/*   Updated: 2021/12/03 14:49:24 by badam            ###   ########.fr       */
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

void	pa(t_list **a, t_list **b)
{
	ft_putstr_fd("pa\n", 1);
	push(a, b);
}

void	pb(t_list **b, t_list **a)
{
	ft_putstr_fd("pb\n", 1);
	push(b, a);
}

void	auto_push(t_list **list, t_list **a, t_list **b)
{
	if (list == a)
		pa(a, b);
	else
		pb(b, a);
}