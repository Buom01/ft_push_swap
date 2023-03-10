/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:57:22 by badam             #+#    #+#             */
/*   Updated: 2021/12/13 00:02:03 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_config
{
	bool	error;
	bool	silent;
	t_list	*sorted;
	size_t	total_len;
	size_t	operations;
	size_t	chunked;
	t_list	*nonchunked_cur;
}	t_config;

void	sa(t_list **a, t_config *cfg);
void	sb(t_list **b, t_config *cfg);
void	ss(t_list **a, t_list **b, t_config *cfg);
void	pa(t_list **a, t_list **b, t_config *cfg);
void	pb(t_list **b, t_list **a, t_config *cfg);
void	ra(t_list **a, t_config *cfg);
void	rb(t_list **b, t_config *cfg);
void	rr(t_list **a, t_list **b, t_config *cfg);
void	rra(t_list **a, t_config *cfg);
void	rrb(t_list **b, t_config *cfg);
void	rrr(t_list **a, t_list **b, t_config *cfg);

void	auto_swap(t_list **list, t_list **a, t_list **b, t_config *cfg);
void	auto_push(t_list **list, t_list **a, t_list **b, t_config *cfg);
void	auto_rotate(t_list **list, t_list **a, t_list **b, t_config *cfg);
void	auto_reverse_rotate(t_list **list, t_list **a, t_list **b,
			t_config *cfg);

bool	lst_contains(int value, t_list *list);
bool	lst_contains_less(int value, t_list *list);
bool	chunk_contains_more(int value, t_list *list, size_t len);
bool	less(t_list *a, t_list *b);
void	new_appended_elem(int value, t_list **list, bool *error);

bool	is_sorted(t_list *a);
int		get_max(t_list *list);
int		get_splitpoint(t_config *cfg);
bool	is_empty(t_list *lst);

void	dump(t_list *a, t_list *b);
int		ft_atoi_err(const char *str, bool *error);

bool	get_first_number(char ***argv, bool *error);
bool	get_next_number(char ***argv, int *argc, bool *error);

void	freeup(t_list **a, t_list **b, t_config *cfg);
int		handle_error(t_list **a, t_list **b, t_config *cfg);
void	sort_triplet(t_list **lst, t_config *cfg);
void	simple_sort(t_list **a, t_list **b, t_config *cfg);
void	check(t_list **a, t_list **b, t_config *cfg);

#endif
