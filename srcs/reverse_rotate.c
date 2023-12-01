/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:18:01 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:29:03 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*runner;

	tmp = ft_lstlast(*stack);
	runner = *stack;
	while (runner != NULL && runner->next != NULL && runner->next->next != NULL)
	{
		runner = runner->next;
	}
	if (runner != NULL)
		runner->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	update_index(stack);
}

void	reverse_rotate_a(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
