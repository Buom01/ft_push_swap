/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:57:22 by badam             #+#    #+#             */
/*   Updated: 2021/12/08 18:15:11 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# define MAX_CHUNK_LEN	43

void	sa(t_list **a, bool silent);
void	sb(t_list **b, bool silent);
void	ss(t_list **a, t_list **b, bool silent);
void	pa(t_list **a, t_list **b, bool silent);
void	pb(t_list **b, t_list **a, bool silent);
void	ra(t_list **a, bool silent);
void	rb(t_list **b, bool silent);
void	rr(t_list **a, t_list **b, bool silent);
void	rra(t_list **a, bool silent);
void	rrb(t_list **b, bool silent);
void	rrr(t_list **a, t_list **b, bool silent);

void	auto_swap(t_list **list, t_list **a, t_list **b, bool silent);
void	auto_push(t_list **list, t_list **a, t_list **b, bool silent);
void	auto_rotate(t_list **list, t_list **a, t_list **b, bool silent);
void	auto_reverse_rotate(t_list **list, t_list **a, t_list **b, bool silent);

bool	lst_contains(int value, t_list *list);
bool	lst_contains_less(int value, t_list *list);
bool	chunk_contains_more(int value, t_list *list, size_t len);
bool	less(t_list *a, t_list *b);
void	new_appended_elem(int value, t_list **list, bool *error);

bool	is_sorted(t_list *a);
int		get_max(t_list *list);
int		get_chunk_splitpoint(t_list *list, size_t len);
int		get_splitpoint(t_list *list);

void	dump(t_list *a, t_list *b);
int		ft_atoi_err(const char *str, bool *error);

void	freeup(t_list **a, t_list **b);
int		handle_error(t_list **a, t_list **b);
void	simple_sort(t_list **a, t_list **b);
void	check(t_list **a, t_list **b);

#endif
