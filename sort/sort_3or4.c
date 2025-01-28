/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3or4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:51 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 15:47:53 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_index0or1(int **tab, int *size_a, int *size_b, int index)
{
	if (index == 0)
	{
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a);
		pa(tab, size_a, size_b);
	}
	else if (index == 1)
	{
		sa(tab, *size_a);
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a);
		pa(tab, size_a, size_b);
	}
}

static void	ft_index2or3(int **tab, int *size_a, int *size_b, int index)
{
	if (index == 2)
	{
		ra(tab, *size_a);
		ra(tab, *size_a);
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a);
		pa(tab, size_a, size_b);
	}
	else if (index == 3)
	{
		rra(tab, *size_a);
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a);
		pa(tab, size_a, size_b);
	}
}

void	ft_sort_4(int **tab, int *size_a, int *size_b)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = tab[0][0];
	if (*size_a == 4)
	{
		while (i < *size_a)
		{
			if (min > tab[i][0])
			{
				min = tab[i][0];
				index = i;
			}
			i++;
		}
		if (index == 0 || index == 1)
			ft_index0or1(tab, size_a, size_b, index);
		if (index == 2 || index == 3)
			ft_index2or3(tab, size_a, size_b, index);
	}
}

void	ft_sort_3(int **tab, int size_a)
{
	while (tab[0][0] > tab[2][0])
		ra(tab, size_a);
	while (tab[1][0] > tab[2][0])
		rra(tab, size_a);
	if (tab[0][0] > tab[1][0])
		sa(tab, size_a);
}
