/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:32:04 by mlaussel          #+#    #+#             */
/*   Updated: 2024/12/10 11:10:20 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_putchar(char c, int *len)
{
	(*len)++;
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		(*len) += 6;
		return (write (1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
	return (0);
}
