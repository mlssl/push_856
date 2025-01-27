/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:06:05 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_search_min(int **tab, int size_a, int *min1, int *min2)
{
	int	i;

	i = 2;
	while (i < size_a)
	{
		if (tab[i][0] < *min1)
		{
			*min2 = *min1;
			*min1 = tab[i][0];
		}
		else if (tab[i][0] < *min2 && tab[i][0] != *min1)
		{
			*min2 = tab[i][0];
		}
		i++;
	}
}

static void	ft_step1(int **tab, int size_b) //, int size_a
{
	if (size_b > 1 && tab[0][1] < tab[1][1])
		sb(tab, size_b); // size_a,
}

static void	ft_step2(int **tab, int size_a, int size_b)
{
	pa(tab, &size_a, &size_b);
	pa(tab, &size_a, &size_b);
}

void	ft_sort_5(int **tab, int *size_a, int *size_b)
{
	int	min1;
	int	min2;
	int	i;
	int	size;

	i = 0;
	size = *size_a;
	min1 = tab[0][0];
	min2 = tab[1][0];
	if (min1 > min2)
	{
		min1 = tab[1][0];
		min2 = tab[0][0];
	}
	ft_search_min(tab, *size_a, &min1, &min2);
	while (i < size)
	{
		if (tab[0][0] == min1 || tab[0][0] == min2)
			pb(tab, size_a, size_b);
		else
			ra(tab, *size_a); //, *size_b
		i++;
	}
	ft_sort_3(tab, *size_a); //, *size_b
	ft_step1(tab, *size_b); //, *size_a,
	ft_step2(tab, *size_a, *size_b);
}
