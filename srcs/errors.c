/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:15:15 by bastien           #+#    #+#             */
/*   Updated: 2021/12/03 00:06:57 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error(t_list **a, t_list **b)
{
	freeup(a, b);
	ft_putstr_fd("Error\n", 1);
	return (1);
}
