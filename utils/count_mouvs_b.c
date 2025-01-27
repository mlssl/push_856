/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mouvs_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:46:32 by mathildelau       #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_ref_b(int **tab, int ref, int div, int size_b)
{
	int	i;

	i = 0;
	while (i < size_b)
	{
		if (tab[i][1] / div % 10 == ref)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	copy_b(int **tab, int **tab_copy, int size_b)
{
	int i;

	i = 0;
	while (i < size_b)
	{
		tab_copy[i][1] = tab[i][1];
		i++;
	}
}

int count_rb(int **tab, int size_b, int ref, int div)
{
	int rb_count;
	int **tab_copy;

	tab_copy = malloc_tab(size_b);
	copy_b(tab, tab_copy, size_b);
	rb_count = 0;
	while ((tab_copy[0][1] / div) % 10 != ref)
	{
		rb_copy(tab_copy, size_b);
		rb_count++;
	}
	return (rb_count);
}

int count_rrb(int **tab, int size_b, int ref, int div)
{
	int rrb_count;
	int **tab_copy;

	tab_copy = malloc_tab(size_b);
	copy_b(tab, tab_copy, size_b);
	rrb_count = 0;
	while ((tab_copy[0][1] / div) % 10 != ref)
	{
		rrb_copy(tab_copy, size_b);
		rrb_count++;
	}
	return (rrb_count);
}

int count_rb_binaire(int **tab, int size_b, int bit)
{
    int rb_count = 1;

    while (((tab[rb_count][1] >> bit) & 1) != 0 && rb_count < size_b)
        rb_count++;
    return rb_count;
}
int count_rrb_binaire(int **tab, int size_b, int bit)
{
    int rrb_count = 1;

    while (((tab[size_b - rrb_count][1] >> bit) & 1) != 0 && rrb_count < size_b)
        rrb_count++;
    return rrb_count;
}
