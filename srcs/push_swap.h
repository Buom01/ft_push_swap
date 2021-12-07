/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:57:22 by badam             #+#    #+#             */
/*   Updated: 2021/12/07 09:28:05 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"

# define MAX_CHUNK_LEN	73

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	auto_swap(t_list **list, t_list **a, t_list **b);
void	auto_push(t_list **list, t_list **a, t_list **b);
void	auto_rotate(t_list **list, t_list **a, t_list **b);
void	auto_reverse_rotate(t_list **list, t_list **a, t_list **b);

bool	lst_contains(int value, t_list *list);
bool	lst_contains_less(int value, t_list *list);
bool	chunk_contains_more(int value, t_list *list, size_t len);
bool	less(t_list *a, t_list *b);
void	new_appended_elem(int value, t_list **list, bool *error);

bool	is_sorted(t_list *a);
int		get_max(t_list *list);
int		get_chunk_splitpoint(t_list *list, size_t len);
int		get_midpoint(t_list *list);

void	dump(t_list *a, t_list *b);
int		ft_atoi_err(const char *str, bool *error);

void	freeup(t_list **a, t_list **b);
int		handle_error(t_list **a, t_list **b);
void	simple_sort(t_list **a, t_list **b);

#endif
