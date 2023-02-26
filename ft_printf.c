/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:14:47 by saltinba          #+#    #+#             */
/*   Updated: 2023/01/05 15:13:46 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_dhex(unsigned int i, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_dhex(i / 16, result);
		ft_dhex(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}

void	ft_uhex(unsigned int i, int *result)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i >= 16)
	{
		ft_uhex(i / 16, result);
		ft_uhex(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}

void	ft_check(va_list *list, char a, int *result)
{
	if (a == 'c')
		ft_putchar(va_arg(*list, int), result);
	else if (a == '%')
		ft_putchar('%', result);
	else if (a == 's')
		ft_putstr(va_arg(*list, char *), result);
	else if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(*list, int), result);
	else if (a == 'x')
		ft_dhex(va_arg(*list, unsigned long long), result);
	else if (a == 'X')
		ft_uhex(va_arg(*list, unsigned long long), result);
	else if (a == 'u')
		ft_unsigned(va_arg(*list, unsigned int), result);
	else if (a == 'p')
	{
		ft_putstr("0x", result);
		ft_pointer(va_arg(*list, unsigned long long), result);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	liste;

	i = 0;
	result = 0;
	va_start(liste, format);
	while (format[i] && format)
	{
		if (format[i] == '%' && format[i + 1])
			ft_check(&liste, format[++i], &result);
		else
			ft_putchar(format[i], &result);
		i++;
	}
	va_end (liste);
	return (result);
}
