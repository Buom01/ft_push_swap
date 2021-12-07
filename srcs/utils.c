/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:23:44 by badam             #+#    #+#             */
/*   Updated: 2021/12/07 09:31:28 by badam            ###   ########.fr       */
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

int	ft_atoi_err(const char *str, bool *error)
{
	int		nb;
	long	nb_prev;
	char	sign;
	char	*c;

	nb = 0;
	nb_prev = 0;
	sign = 1;
	c = (char *)str;
	while (*c == ' ' || (*c >= '\t' && *c <= '\r'))
		c++;
	if (*c == '-' || *c == '+')
		if (*(c++) == '-')
			sign *= -1;
	while (*c >= '0' && *c <= '9')
	{
		nb = ((long)nb * 10 + (*(c++) - '0') * sign);
		if ((sign == 1 && nb < nb_prev)
			|| (sign == -1 && nb > nb_prev))
			*error = true;
		nb_prev = nb;
	}
	return ((int)nb);
}
