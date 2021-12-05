/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:10:43 by badam             #+#    #+#             */
/*   Updated: 2021/12/05 23:16:53 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *a)
{
	while (a->next)
	{
		if (!less(a, a->next))
			return (false);
		a = a->next;
	}
	return (true);
}

int	get_max(t_list *list)
{
	int	max;

	max = *((int *)list->content);
	list = list->next;
	while (list)
	{
		if (*((int *)list->content) > max)
			max = *((int *)list->content);
		list = list->next;
	}
	return (max);
}

int	get_chunk_splitpoint(t_list *list, size_t len)
{
	int	min;
	int	max;

	min = *((int *)list->content);
	max = *((int *)list->content);
	list = list->next;
	while (--len && list)
	{
		if (*((int *)list->content) > max)
			max = *((int *)list->content);
		if (*((int *)list->content) < min)
			min = *((int *)list->content);
		list = list->next;
	}
	if ((max - min + 1) / 2 > MAX_CHUNK_LEN)
		return (min + MAX_CHUNK_LEN);
	else
		return (min + ((max - min + 1) / 2));
}

int	get_midpoint(t_list *list)
{
	int	min;
	int	max;

	min = *((int *)list->content);
	max = *((int *)list->content);
	list = list->next;
	while (list)
	{
		if (*((int *)list->content) > max)
			max = *((int *)list->content);
		if (*((int *)list->content) < min)
			min = *((int *)list->content);
		list = list->next;
	}
	return (min + ((max - min + 1) / 2));
}
