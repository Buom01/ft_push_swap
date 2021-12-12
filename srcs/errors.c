/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:15:15 by bastien           #+#    #+#             */
/*   Updated: 2021/12/12 15:29:51 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeup(t_list **a, t_list **b, t_config *cfg)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	ft_lstclear(&(cfg->sorted), free);
}

int	handle_error(t_list **a, t_list **b, t_config *cfg)
{
	freeup(a, b, cfg);
	ft_putstr_fd("Error\n", 2);
	return (1);
}
