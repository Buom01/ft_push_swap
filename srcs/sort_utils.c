/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:10:43 by badam             #+#    #+#             */
/*   Updated: 2021/12/12 22:44:46 by badam            ###   ########.fr       */
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

static int	chunksize_for_listlen(int len)
{
	return (len / 9 + 9);
}

int	get_splitpoint(t_list *list, t_config *cfg)
{
	int	chunk_size;

	chunk_size = chunksize_for_listlen(ft_lstsize(list));
	if (ft_lstsize(list) - 3 <= chunk_size)
		chunk_size = ft_lstsize(list) - 3;
	while (chunk_size)
	{
		cfg->nonchunked_cur = cfg->nonchunked_cur->next;
		++cfg->chunked;
		--chunk_size;
	}
	return (*((int *)cfg->nonchunked_cur->content));
}

bool	is_empty(t_list *lst)
{
	return (!lst || !lst->next);
}
