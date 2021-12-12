/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:10:43 by badam             #+#    #+#             */
/*   Updated: 2021/12/13 00:02:03 by badam            ###   ########.fr       */
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
	return (len / 9 + 10);
}

int	get_splitpoint(t_config *cfg)
{
	int		chunk_size;
	ssize_t	non_chunked;

	non_chunked = cfg->total_len - cfg->chunked;
	chunk_size = chunksize_for_listlen(non_chunked);
	if (non_chunked - 3 <= chunk_size)
		chunk_size = non_chunked - 3;
	while (chunk_size)
	{
		cfg->nonchunked_cur = cfg->nonchunked_cur->next;
		--chunk_size;
	}
	return (*((int *)cfg->nonchunked_cur->content));
}

bool	is_empty(t_list *lst)
{
	return (!lst || !lst->next);
}
