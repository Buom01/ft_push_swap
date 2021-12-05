/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:22:52 by badam             #+#    #+#             */
/*   Updated: 2021/12/03 14:49:28 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **list)
{
	t_list	*tmp_place;

	if (ft_lstsize(*list) < 2)
		return ;
	tmp_place = *list;
	*list = (*list)->next;
	tmp_place->next = (*list)->next;
	(*list)->next = tmp_place;
}

void	sa(t_list **a)
{
	ft_putstr_fd("sa\n", 1);
	swap(a);
}

void	sb(t_list **b)
{
	ft_putstr_fd("sb\n", 1);
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	ft_putstr_fd("ss\n", 1);
	swap(a);
	swap(b);
}

void	auto_swap(t_list **list, t_list **a, t_list **b)
{
	if (list == a)
		sa(a);
	else
		sb(b);
}
