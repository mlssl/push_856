/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:00:51 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(int	**tab, int *size_a, int *size_b)
{
	int	i;

	i = *size_a;

	if (*size_b > 0)
	{
		write(1, "pa\n", 3);
		(*size_a)++;
		while (i > 0)
		{
			tab[i][0] = tab[i - 1][0];
			i--;
		}
		tab[0][0] = tab [0][1];
		i = 0;
		while (i < *size_b - 1)
		{
			tab[i][1] = tab[i + 1][1];
			i++;
		}
	}
	(*size_b)--;

}

void	pb(int	**tab, int *size_a, int *size_b)
{
	int	j;
	int	i;

	j = 0;
	i = *size_b;
	if (*size_a > 0)
	{
		write(1, "pb\n", 3);
		(*size_b)++;
		while (i > 0)
		{
			tab[i][1] = tab[i - 1][1];
			i--;
		}
		tab[0][1] = tab [0][0];
		while (j < *size_a - 1)
		{
			tab[j][0] = tab[j + 1][0];
			j++;
		}
	}
	(*size_a)--;
}
