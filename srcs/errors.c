/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:15:15 by bastien           #+#    #+#             */
/*   Updated: 2021/12/07 17:34:35 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeup(t_list **a, t_list **b)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
}

int	handle_error(t_list **a, t_list **b)
{
	freeup(a, b);
	ft_putstr_fd("Error\n", 1);
	return (1);
}
