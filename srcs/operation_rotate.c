/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:55 by badam             #+#    #+#             */
/*   Updated: 2021/12/07 17:39:22 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*elem;

	if (ft_lstsize(*list) < 2)
		return ;
	elem = *list;
	*list = (*list)->next;
	elem->next = NULL;
	ft_lstadd_back(list, elem);
}

void	ra(t_list **a, bool silent)
{
	if (!silent)
		ft_putstr_fd("ra\n", 1);
	rotate(a);
}

void	rb(t_list **b, bool silent)
{
	if (!silent)
		ft_putstr_fd("rb\n", 1);
	rotate(b);
}

void	rr(t_list **a, t_list **b, bool silent)
{
	if (!silent)
		ft_putstr_fd("rr\n", 1);
	rotate(a);
	rotate(b);
}

void	auto_rotate(t_list **list, t_list **a, t_list **b, bool silent)
{
	if (list == a)
		ra(a, silent);
	else
		rb(b, silent);
}
