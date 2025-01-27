/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3or4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:51 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_index0or1(int **tab, int *size_a, int *size_b, int index)
{
	if (index == 0)
	{
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a); //, *size_b
		pa(tab, size_a, size_b);
	}
	else if (index == 1)
	{
		sa(tab, *size_a); //, size_b
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a); //, *size_b
		pa(tab, size_a, size_b);
	}
}

static void	ft_index2or3(int **tab, int *size_a, int *size_b, int index)
{
	if (index == 2)
	{
		ra(tab, *size_a); //, size_b
		ra(tab, *size_a); //, size_b
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a); //, *size_b
		pa(tab, size_a, size_b);
	}
	else if (index == 3)
	{
		rra(tab, *size_a); //, size_b
		pb(tab, size_a, size_b);
		ft_sort_3(tab, *size_a); //, *size_b
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
/*Tant que le plus petit n'est pas en premiere position
Tant que le plus grand n'est pas en derniere position
Si le permier et le deuxieme ne sont pas a la bonne place, on bouge*/

void	ft_sort_3(int **tab, int size_a) //, int size_b
{
	while (tab[0][0] > tab[2][0])
		ra(tab, size_a); //, size_b
	while (tab[1][0] > tab[2][0])
		rra(tab, size_a); //, size_b
	if (tab[0][0] > tab[1][0])
		sa(tab, size_a); //, size_b
}
