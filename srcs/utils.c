/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:23:44 by badam             #+#    #+#             */
/*   Updated: 2021/12/03 21:10:33 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dump(t_list *a, t_list *b)
{
	size_t	la;
	size_t	lb;
	size_t	max_len;

	la = ft_lstsize(a);
	lb = ft_lstsize(b);
	max_len = ft_max(la, lb);
	ft_putstr_fd("================\n", 1);
	while (max_len)
	{
		if (la == max_len && la--)
		{
			ft_putnbr_fd(*((int *)a->content), 1);
			a = a->next;
		}
		ft_putstr_fd("\t", 1);
		if (lb == max_len-- && lb--)
		{
			ft_putnbr_fd(*((int *)b->content), 1);
			b = b->next;
		}
		ft_putstr_fd("\t\n", 1);
	}
	ft_putstr_fd("---\t---\t\n a \t b \t\n================\n", 1);
}
