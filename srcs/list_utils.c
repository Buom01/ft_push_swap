/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:08:16 by badam             #+#    #+#             */
/*   Updated: 2021/12/05 22:46:22 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	lst_contains(int value, t_list *list)
{
	while (list)
	{
		if (*((int *)list->content) == value)
			return (true);
		list = list->next;
	}
	return (false);
}

bool	lst_contains_less(int value, t_list *list)
{
	while (list)
	{
		if (*((int *)list->content) < value)
			return (true);
		list = list->next;
	}
	return (false);
}

bool	chunk_contains_more(int value, t_list *list, size_t len)
{
	while (list && len--)
	{
		if (*((int *)list->content) >= value)
			return (true);
		list = list->next;
	}
	return (false);
}

bool	less(t_list *a, t_list *b)
{
	return (*((int *)a->content) < *((int *)b->content));
}

void	new_appended_elem(int value, t_list **list, bool *error)
{
	int		*content;
	t_list	*elem;

	elem = *list;
	if (lst_contains(value, *list))
	{
		*error = true;
		return ;
	}
	content = malloc(sizeof(int));
	if (!content)
	{
		*error = true;
		return ;
	}
	*content = value;
	elem = ft_lstnew(content);
	if (!elem)
	{
		free(content);
		*error = true;
		return ;
	}
	ft_lstadd_back(list, elem);
}
