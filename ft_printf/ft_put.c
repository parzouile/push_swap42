/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:37:39 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/08 02:43:01 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(const char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(-nb));
	if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_putnbrd(unsigned int nb)
{
	if (nb / 10)
		return (ft_putnbrd(nb / 10) + ft_putnbrd(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}
