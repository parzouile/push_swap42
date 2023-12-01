/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:37:10 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/08 03:02:11 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexa_min(unsigned int nb)
{
	if (nb >= 16)
		return (ft_hexa_min(nb / 16) + ft_hexa_min(nb % 16));
	if (nb >= 10)
		return (ft_putchar((nb % 10) + 'a'));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_hexa_cap(unsigned int nb)
{
	if (nb >= 16)
		return (ft_hexa_cap(nb / 16) + ft_hexa_cap(nb % 16));
	if (nb >= 10)
		return (ft_putchar((nb % 10) + 'A'));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_hexa_long(unsigned long int nb)
{
	if (nb >= 16)
		return (ft_hexa_long(nb / 16) + ft_hexa_long(nb % 16));
	if (nb >= 10)
		return (ft_putchar((nb % 10) + 'a'));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_puthexa(void *x)
{
	unsigned long int	a;

	if (!x)
		return (ft_putstr("(nil)"));
	a = (unsigned long int)x;
	write(1, "0x", 2);
	return (2 + ft_hexa_long(a));
}
