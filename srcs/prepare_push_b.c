/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:56:29 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:56:36 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_push_b(t_list **a, t_list **b, t_list *node)
{
	long	size_a;
	long	size_b;

	size_a = len_stack(*a);
	size_b = len_stack(*b);
	if (node->index <= (size_b / 2) && node->target->index <= (size_a / 2))
		rotate_all(b, a, node);
	else if (node->index > (size_b / 2) && node->target->index > (size_a / 2))
		reverse_rotate_all(b, a, node);
	prepare_a(b, node, size_b);
	prepare_b(a, node, size_a);
	push_a(a, b);
}
