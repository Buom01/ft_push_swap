/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:40:35 by badam             #+#    #+#             */
/*   Updated: 2021/12/03 01:03:16 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*init_array(size_t len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	bool	positive;
	size_t	len;
	long	nb;
	long	nb_cpy;
	char	*str;

	positive = n > 0;
	nb = (n * positive) + ((long)n * !positive * -1);
	nb_cpy = n;
	len = !positive + 1;
	while (nb_cpy / 10 && ++len)
		nb_cpy /= 10;
	str = init_array(len);
	if (!str)
		return (NULL);
	while (len - !positive > 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}
