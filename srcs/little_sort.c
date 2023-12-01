/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:31:12 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:37:17 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *a)
{
	t_list	*max;

	max = a;
	a = a->next;
	while (a != NULL)
	{
		if (a->content > max->content)
			max = a;
		a = a->next;
	}
	return (max);
}

t_list	*find_min(t_list *a)
{
	t_list	*min;

	min = a;
	a = a->next;
	while (a != NULL)
	{
		if (a->content < min->content)
			min = a;
		a = a->next;
	}
	return (min);
}

void	little_sort(t_list **a)
{
	t_list	*max;

	max = find_max(*a);
	if (max->index == 0)
		rotate_a(a);
	else if (max->index == 1)
		reverse_rotate_a(a);
	if (!check_sorted(*a))
		swap_a(a);
}
