/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:32:59 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/18 14:53:25 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_sort(t_list **a)
{
	t_list	*min;

	min = find_min(*a);
	if (min->index <= len_stack(*a) / 2)
		while ((*a)->content != min->content)
			rotate_a(a);
	else
		while ((*a)->content != min->content)
			reverse_rotate_a(a);
}

void	big_sort(t_list **a)
{
	int		size;
	t_list	*b;

	b = NULL;
	size = len_stack(*a);
	push_b(a, &b);
	if (--size > 3 && check_sorted(*a) == 0)
		push_b(a, &b);
	while (--size > 3 && check_sorted(*a) == 0)
	{
		find_target_a(a, b);
		init_cost(*a, b);
		prepare_push_a(a, &b);
	}
	if (check_sorted(*a) == 0)
		little_sort(a);
	while (b)
	{
		find_target_b(&b, *a);
		init_cost(b, *a);
		prepare_push_b(a, &b);
	}
	finish_sort(a);
}
