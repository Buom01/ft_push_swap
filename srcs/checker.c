/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:57:28 by badam             #+#    #+#             */
/*   Updated: 2021/12/12 15:29:13 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_list		*a;
	t_list		*b;

	ft_memset(&cfg, 0, sizeof(cfg));
	a = NULL;
	b = NULL;
	cfg.silent = true;
	--argc;
	++argv;
	if (!argc)
		return (0);
	get_first_number(&argv, &cfg.error);
	while (!cfg.error && argc)
	{
		new_appended_elem(ft_atoi_err(*argv, &cfg.error), &a, &cfg.error);
		get_next_number(&argv, &argc, &cfg.error);
	}
	if (cfg.error)
		return (handle_error(&a, &b, &cfg));
	check(&a, &b, &cfg);
	freeup(&a, &b, &cfg);
	return (0);
}
