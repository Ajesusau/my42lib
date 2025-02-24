/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:14:57 by anareval          #+#    #+#             */
/*   Updated: 2025/01/31 16:34:48 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		cont;

	cont = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		cont++;
	}
	if (nb >= 10)
		cont += ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	return (cont);
}

int	ft_putnbrex_fd(int n, int fd, int i)
{
	long	nb;
	int		cont;
	char	c;

	cont = 1;
	nb = (unsigned int)n;
	if (i == 1)
		c = 55;
	else
		c = 87;
	if (nb >= 16)
		cont += ft_putnbrex_fd(nb / 16, fd, i);
	if (nb % 16 < 10)
		ft_putchar_fd(nb % 16 + '0', fd);
	else
		ft_putchar_fd(nb % 16 + c, fd);
	return (cont);
}

int	ft_putnbruns_fd(int n, int fd)
{
	long	nb;
	int		cont;

	cont = 1;
	nb = (unsigned int)n;
	if (nb >= 10)
		cont += ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	return (cont);
}
