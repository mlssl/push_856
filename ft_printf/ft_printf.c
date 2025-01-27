/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:32:19 by mlaussel          #+#    #+#             */
/*   Updated: 2024/12/10 12:54:12 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_args(const char *str)
{
	if (str[0] == 'c' || str[0] == 's' || str[0] == 'd' || str[0] == 'p'
		|| str[0] == 'i' || str[0] == 'u' || str[0] == 'x' || str[0] == 'X'
		|| str[0] == '%')
		return (1);
	return (0);
}

static int	ft_prepare_void(va_list args, int *len)
{
	void	*ptr;
	int		check_write;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		(*len) += 5;
		return (write(1, "(nil)", 5));
	}
	else
	{
		(*len) += 2;
		check_write = write(1, "0x", 2);
		if (check_write == -1)
			return (-1);
		ft_pointer((unsigned long)ptr, "0123456789abcdef", len);
	}
	return (0);
}

static void	ft_choice_print(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", len);
	if (c == 'x')
		ft_hexa(va_arg(args, int), "0123456789abcdef", len);
	if (c == 'X')
		ft_hexa(va_arg(args, int), "0123456789ABCDEF", len);
	if (c == '%')
		ft_putchar('%', len);
	if (c == 'u')
		ft_unsigned(va_arg(args, unsigned int), len);
	if (c == 'p')
		ft_prepare_void(args, len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i++] == '\0')
				break ;
			if (ft_is_args(str + i) == 1)
				ft_choice_print(str[i++], args, &len);
			else
				return (va_end(args), -1);
		}
		else
			ft_putchar(str[i++], &len);
	}
	va_end(args);
	return (len);
}
