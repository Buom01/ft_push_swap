/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 01:16:46 by badam             #+#    #+#             */
/*   Updated: 2021/12/13 00:02:14 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pre_sort(t_config *cfg)
{
	bool	sorted;
	t_list	*cursor;
	void	*tmp;

	cfg->total_len = ft_lstsize(cfg->sorted);
	sorted = false;
	while (!sorted)
	{
		sorted = true;
		cursor = cfg->sorted;
		while (cursor && cursor->next)
		{
			if (!less(cursor, cursor->next))
			{
				sorted = false;
				tmp = cursor->content;
				cursor->content = cursor->next->content;
				cursor->next->content = tmp;
			}
			cursor = cursor->next;
		}
	}
	cfg->nonchunked_cur = cfg->sorted;
}

ssize_t	shortest_way_to(t_list *list, int value)
{
	ssize_t	from_top;
	ssize_t	from_end;

	from_top = 0;
	from_end = 0;
	while (list)
	{
		if (*((int *)list->content) == value)
		{
			from_end = 0;
			break ;
		}
		++from_top;
		list = list->next;
	}
	while (list)
	{
		++from_end;
		list = list->next;
	}
	if (from_top < from_end)
		return (from_top);
	else
		return (-from_end);
}

void	sorts(t_list **a, t_list **b, size_t len, t_config *cfg)
{
	ssize_t	way_to_next;

	while (len)
	{
		if (len == 2)
		{
			if (less(*b, (*b)->next))
				sb(b, cfg);
		}
		else if (len > 2)
		{
			way_to_next = shortest_way_to(*b, get_max(*b));
			if (way_to_next > 0)
			{
				while (way_to_next-- > 0)
					rb(b, cfg);
			}
			else if (way_to_next < 0)
				while (way_to_next++ < 0)
					rrb(b, cfg);
		}
		pa(a, b, cfg);
		--len;
	}
}

void	form_chunks(t_list **a, t_list **b, t_config *cfg)
{
	int		splitpoint;

	if (is_sorted(*a))
		return ;
	splitpoint = get_splitpoint(cfg);
	while (lst_contains_less(splitpoint, *a))
	{
		if (*((int *)(*a)->content) < splitpoint)
		{
			++cfg->chunked;
			pb(b, a, cfg);
		}
		else
			ra(a, cfg);
	}
	if (cfg->total_len - cfg->chunked > 3)
		form_chunks(a, b, cfg);
	else if (!is_sorted(*a))
		sort_triplet(a, cfg);
}

void	simple_sort(t_list **a, t_list **b, t_config *cfg)
{
	pre_sort(cfg);
	if (cfg->total_len > 3)
	{
		form_chunks(a, b, cfg);
		sorts(a, b, cfg->chunked, cfg);
	}
	else if (!is_sorted(*a))
		sort_triplet(a, cfg);
}
