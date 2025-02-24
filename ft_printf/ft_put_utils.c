/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:16:25 by anareval          #+#    #+#             */
/*   Updated: 2025/01/31 16:34:34 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	ft_putex(unsigned long long n, int fd)
{
	int					cont;
	unsigned long long	nb;

	cont = 1;
	nb = (unsigned long long) n;
	if (nb >= 16)
		cont += ft_putex(nb / 16, fd);
	if (nb % 16 < 10)
		ft_putchar_fd(nb % 16 + '0', fd);
	else
		ft_putchar_fd(nb % 16 + 87, fd);
	return (cont);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	str;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	str = (unsigned long long) ptr;
	return (ft_putstr_fd("0x", 1) + ft_putex(str, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int		cont;

	cont = 0;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(fd, s, 1);
		s++;
		cont ++;
	}
	return (cont);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
