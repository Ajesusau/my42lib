/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:01:46 by anareval          #+#    #+#             */
/*   Updated: 2025/01/31 15:48:49 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_fomat(char c, va_list arg);

int	ft_printf(char const *str, ...)
{
	int		cont;
	int		i;
	va_list	arg;

	va_start(arg, str);
	cont = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cont += select_fomat((char)str[i], arg);
		}
		else
			cont += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arg);
	return (cont);
}

static int	select_fomat(char c, va_list arg)
{
	int	cont;

	cont = 0;
	if (c == 'c')
		cont += ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		cont += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
		cont += ft_putptr(va_arg(arg, char *));
	else if (c == 'd')
		cont += ft_putnbr_fd(va_arg(arg, long), 1);
	else if (c == 'i')
		cont += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		cont += ft_putnbruns_fd(va_arg(arg, int), 1);
	else if (c == 'x')
		cont += ft_putnbrex_fd(va_arg(arg, long), 1, 0);
	else if (c == 'X')
		cont += ft_putnbrex_fd(va_arg(arg, long), 1, 1);
	else if (c == '%')
		cont += ft_putchar_fd('%', 1);
	return (cont);
}
