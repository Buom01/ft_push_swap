/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:55 by badam             #+#    #+#             */
/*   Updated: 2021/12/11 00:17:28 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*elem;

	if (is_empty(*list))
		return ;
	elem = *list;
	*list = (*list)->next;
	elem->next = NULL;
	ft_lstadd_back(list, elem);
}

void	ra(t_list **a, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("ra\n", 1);
	rotate(a);
	++(cfg->operations);
}

void	rb(t_list **b, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("rb\n", 1);
	rotate(b);
	++(cfg->operations);
}

void	rr(t_list **a, t_list **b, t_config *cfg)
{
	if (!cfg->silent)
		ft_putstr_fd("rr\n", 1);
	rotate(a);
	rotate(b);
	++(cfg->operations);
}

void	auto_rotate(t_list **list, t_list **a, t_list **b, t_config *cfg)
{
	if (list == a)
		ra(a, cfg);
	else
		rb(b, cfg);
}
