/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mouvs_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:46:32 by mathildelau       #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_ref_a(int **tab, int ref, int div, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		if (tab[i][0] / div % 10 == ref)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	copy_a(int **tab, int **tab_copy, int size_a)
{
	int i;

	i = 0;
	while (i < size_a)
	{
		tab_copy[i][0] = tab[i][0];
		i++;
	}
}

int	count_ra(int **tab, int size_a, int ref, int div)
{
	int	ra_count;
	int **tab_copy;

	tab_copy = malloc_tab(size_a);
	copy_a(tab, tab_copy, size_a);
	ra_count = 0;
	while ((tab_copy[0][0] / div) % 10 != ref)
	{
		ra_copy(tab_copy, size_a);
		ra_count++;
	}
	return (ra_count);
	
}

int count_rra(int **tab, int size_a, int ref, int div)
{
	int rra_count;
	int **tab_copy;

	tab_copy = malloc_tab(size_a);
	copy_a(tab, tab_copy, size_a);
	rra_count = 0;
	while ((tab_copy[0][0] / div) % 10 != ref)
	{
		rra_copy(tab_copy, size_a);
		rra_count++;
	}
	return (rra_count);
}

// int	count_ra_binaire(int **tab, int size_a, int bit)
// {
// 	int	ra_count;
// 	int	**tab_copy;

// 	tab_copy = malloc_tab(size_a);
// 	copy_a(tab, tab_copy, size_a);
// 	ra_count = 0;
// 	while (((tab[0][0] >> bit) & 1) != 0 && ra_count < size_a)
// 	//while (((tab[0][0] >> bit) & 1) != 0)
// 	{
// 		ra_copy(tab_copy, size_a);
// 		ra_count++;
// 	}
// 	return (ra_count);
// }

// int	count_rra_binaire(int **tab, int size_a, int bit)
// {
// 	int	rra_count;
// 	int	**tab_copy;

// 	tab_copy = malloc_tab(size_a);
// 	copy_a(tab, tab_copy, size_a);
// 	rra_count = 0;
// 	while (((tab[0][0] >> bit) & 1) != 0 && rra_count < size_a)
// 	//while (((tab[0][0] >> bit) & 1) != 0)
// 	{
// 		rra_copy(tab_copy, size_a);
// 		rra_count++;
// 	}
// 	return (rra_count);
// }

int count_ra_binaire(int **tab, int size_a, int bit)
{
    int ra_count = 1;

    while (((tab[ra_count][0] >> bit) & 1) != 0 && ra_count < size_a)
        ra_count++;
    return (ra_count);
}

int count_rra_binaire(int **tab, int size_a, int bit)
{
    int rra_count = 1;

    while (((tab[size_a - rra_count][0] >> bit) & 1) != 0 && rra_count < size_a)
        rra_count++;
    return (rra_count);
}
