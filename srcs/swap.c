/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:14:56 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:20:39 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	long	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	swap_a(t_list **a)
{
	swap(a);
	printf("sa\n");
}

void	swap_b(t_list **b)
{
	swap(b);
	printf("sb\n");
}

void	swap_ab(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
