/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:03:28 by badam             #+#    #+#             */
/*   Updated: 2021/12/10 21:09:33 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_triplet(t_list **a)
{
	if (ft_lstsize(*a) >= 3)
	{
		if (less((*a)->next, *a))
		{
			if (less(*a, (*a)->next->next))
				sa(a, false);
			else
			{
				ra(a, false);
				if (less((*a)->next, *a))
					sa(a, false);
			}
		}
		else if (less((*a)->next->next, *a))
			rra(a, false);
		else
		{
			rra(a, false);
			sa(a, false);
		}
	}
	else if (!is_sorted(*a))
		sa(a, false);
}
