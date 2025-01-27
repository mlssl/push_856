/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:23 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


int	ft_intlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len = 1;
		return (len);
	}
	while (nb != 0)
	{
		nb = nb /10;
		len++;
	}
	return (len);
}

int	search_maxi(int **tab, int size_a)
{
	int	max;
	int	i;

	i = 1;
	max = tab[0][0];
	while (i < size_a)
	{
		if (tab[i][0] > max)
			max = tab[i][0];
		i++;
	}
	return (max);
}

int	search_ref_max(int **tab, int ref, int div, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ref == 9)
		return (10);
	while (j < 9)
	{
		while (i < size)
		{
			if (tab[i][0] / div % 10 == ref + j)
			{
				ref = tab[i][0] / div % 10;
				return (ref);
			}
			i++;
		}
		j++;
		i = 0;
	}
	if (ref == 8)
	i = 0;
	j = 1;
	while (j < 9)
	{
		while (i < size)
		{
			if (tab[i][0] / div % 10 == 9)
				return (10);
			i++;
		}
		j++;
		i = 0;
	}
	return (9);
}

int	search_ref_min(int **tab, int ref, int div, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ref == 0)
		return (-1);
	while (j > 0)
	{
		while (i < size)
		{
			if (tab[i][1] / div % 10 == ref - j)
			{
				ref = tab[i][1] / div % 10;
				return (ref);
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
