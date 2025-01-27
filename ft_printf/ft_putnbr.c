/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:32:10 by mlaussel          #+#    #+#             */
/*   Updated: 2024/12/10 13:10:44 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	my_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_putnbr_base(int nbr, char *base, int *len)
{
	int	length;

	length = my_strlen(base);
	if (nbr == INT_MIN)
	{
		(*len) += 11;
		return (write(1, "-2147483648", 11));
	}
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr < length)
		ft_putchar(base[nbr], len);
	if (nbr >= length)
	{
		ft_putnbr_base(nbr / length, base, len);
		ft_putnbr_base(nbr % length, base, len);
	}
	return (0);
}

void	ft_unsigned(unsigned int n, int *len)
{
	if (n > 9)
		ft_unsigned(n / 10, len);
	ft_putchar((n % 10) + '0', len);
}

void	ft_pointer(unsigned long nbr, char *base, int *len)
{
	unsigned long	length;

	length = my_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr < length)
	{
		ft_putchar(base[nbr], len);
	}
	if (nbr >= length)
	{
		ft_pointer(nbr / length, base, len);
		ft_pointer(nbr % length, base, len);
	}
}

void	ft_hexa(int nbr, char *base, int *len)
{
	unsigned int	length;
	unsigned int	unsigned_nbr;

	unsigned_nbr = (unsigned int)nbr;
	length = ft_strlen(base);
	if (unsigned_nbr < length)
	{
		ft_putchar(base[unsigned_nbr], len);
	}
	else
	{
		ft_putnbr_base(unsigned_nbr / length, base, len);
		ft_putnbr_base(unsigned_nbr % length, base, len);
	}
}
