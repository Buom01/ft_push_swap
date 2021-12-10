/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:03:28 by badam             #+#    #+#             */
/*   Updated: 2021/12/10 23:02:23 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_triplet(t_list **a, t_config *cfg)
{
	if (ft_lstsize(*a) >= 3)
	{
		if (less((*a)->next, *a))
		{
			if (less(*a, (*a)->next->next))
				sa(a, cfg);
			else
			{
				ra(a, cfg);
				if (less((*a)->next, *a))
					sa(a, cfg);
			}
		}
		else if (less((*a)->next->next, *a))
			rra(a, cfg);
		else
		{
			rra(a, cfg);
			sa(a, cfg);
		}
	}
	else if (!is_sorted(*a))
		sa(a, cfg);
}
