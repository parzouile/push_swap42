/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:56:19 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:57:33 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_list
{
	long			content;
	long			index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

int		check_sorted(t_list *stack);
int		len_stack(t_list *stack);
void	update_index(t_list **stack);
t_list	*find_max(t_list *a);
t_list	*find_min(t_list *a);
void	little_sort(t_list **a);
void	find_target_a(t_list **a, t_list *b);
void	find_target_b(t_list **a, t_list *b);
void	init_cost(t_list *actual, t_list *other);
t_list	*find_less_cost(t_list *stack);
void	rotate_all(t_list **a, t_list **b, t_list *node);
void	reverse_rotate_all(t_list **a, t_list **b, t_list *node);
void	prepare_a(t_list **a, t_list *node, long size_a);
void	prepare_b(t_list **a, t_list *node, long size_a);
void	prepare_push_a(t_list **a, t_list **b, t_list *node);
void	prepare_push_b(t_list **a, t_list **b, t_list *node);

//different rotation
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ab(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	reverse_rotate_ab(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);

#endif