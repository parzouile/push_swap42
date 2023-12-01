/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:36:00 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/16 10:26:16 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_aux(const char *str, size_t i, va_list *res)
{
	if (str[i + 1] == 'c')
		return (ft_putchar((char) va_arg(*res, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(*res, const char *)));
	else if (str[i + 1] == 'p')
		return (ft_puthexa(va_arg(*res, void *)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(*res, int)));
	else if (str[i + 1] == 'u')
		return (ft_putnbrd(va_arg(*res, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_hexa_min(va_arg(*res, unsigned int)));
	else if (str[i + 1] == 'X')
		return (ft_hexa_cap(va_arg(*res, unsigned int)));
	else
		return (ft_putchar(str[i]));
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	n;
	va_list	res;

	if (!str)
		return (-1);
	va_start(res, str);
	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			n += ft_put_aux(str, i, &res);
			i ++;
		}
		else
			n += ft_putchar(str[i]);
		i ++;
	}
	va_end(res);
	return (n);
}
