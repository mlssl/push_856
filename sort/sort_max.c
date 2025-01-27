/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:06:19 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	search_mini(int **tab, int size_a)
{
	int	mini;
	int	i;

	i = 1;
	mini = tab[0][0];
	while (i < size_a)
	{
		if (tab[i][0] < mini)
			mini = tab[i][0];
		i++;
	}
	return (mini);
}

static int	search_maxi_b(int **tab, int size_a)
{
	int	max;
	int	i;

	i = 1;
	max = tab[0][1];
	while (i < size_a)
	{
		if (tab[i][1] > max)
			max = tab[i][1];
		i++;
	}
	return (max);
}

void	ft_sort_max(int **tab, int *size_a, int *size_b)
{
	int	mini;
	int	maxi;
	int	i;
	int	size;
	int	pivot;

	mini = search_mini(tab, *size_a);
	maxi = search_maxi(tab, *size_a);
	pivot = (maxi + mini) / 2;
	size = *size_a;
	i = 0;

	//separer en deux piles
	while (i < size)
	{
		if (tab[0][0] <= pivot)
			pb(tab, size_a, size_b);
		else
			ra(tab, *size_a); //, *size_b
		i++;
	}

	//trier pile a
	i = 0;
	while (*size_a > 1)
	{
		mini = search_mini(tab, *size_a);
		if (tab[0][0] == mini)
			pb(tab, size_a, size_b);
		else
			ra(tab, *size_a); //, *size_b
		i++;
	}

	//trier pile b
	i = 0;
	while (*size_b > 0)
	{
		maxi = search_maxi_b(tab, *size_b);
		if (tab[0][1] == maxi)
			pa(tab, size_a, size_b);
		else
			rb(tab, *size_b); // *size_a,
	}
}
