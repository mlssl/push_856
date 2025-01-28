/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:11:44 by mathildelau       #+#    #+#             */
/*   Updated: 2025/01/28 16:07:52 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ENELVER
#include <stdio.h>

static void	display_piles(int **tab, int size_a, int size_b)
{
	int	i;

	ft_printf("Pile A: ");
	for (i = 0; i < size_a; i++)
		ft_printf("%d ", tab[i][0]);
	write(1, "\n", 1);
	ft_printf("Pile B: ");
	for (i = 0; i < size_b; i++)
		ft_printf("%d ", tab[i][1]);
	write(1, "\n", 1);
}

static int	all_same_bit(int **tab, int *size_a, int bit)
{
	int	first_bit;
	int	i;

	if (*size_a <= 1)
		return (1);
	first_bit = (tab[0][0] >> bit) & 1;
	i = 1;
	while (i < *size_a)
	{
		if (((tab[i][0] >> bit) & 1) != first_bit)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_max_bit(int **tab, int *size_a)
{
	int	max_bits;
	int	max_value;

	max_value = search_maxi(tab, *size_a);
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	return_in_b(int **tab, int *size_a, int *size_b, int bit)
{
	int	i;
	int	save;
	int	max_bits;

	i = 0;
	save = *size_b;
	max_bits = ft_max_bit(tab, size_a);
	if (bit + 1 >= max_bits)
	{
		while (*size_b > 0)
			pa(tab, size_a, size_b);
	}
	else
	{
		while (i++ < save)
		{
			if (((tab[0][1] >> (bit + 1)) & 1) == 0)
				rb(tab, *size_b);
			else if (((tab[0][1] >> (bit + 1)) & 1) != 0)
				pa(tab, size_a, size_b);
		}
	}
}

static void	ft_is_0(int **tab, int *size_a, int *size_b, int bit)
{
	int	save;
	int	i;

	save = *size_a;
	i = 0;
	if (all_same_bit(tab, size_a, bit) == 1)
	{
		bit++;
	}
	while (i++ < save)
	{
		if (is_sorted(tab, *size_a) == 1)
			break ;
		else if (((tab[0][0] >> bit) & 1) == 0)
			pb(tab, size_a, size_b);
		else
			ra(tab, *size_a);
	}
}

void	radix_binary(int **tab, int *size_a, int *size_b)
{
	int	max_bits;
	int	bit;
	int	negative;

	negative = ft_negative_part_1(tab, size_a);
	display_piles(tab, *size_a, *size_b);
	max_bits = ft_max_bit(tab, size_a);
	bit = -1;
	while (++bit <= max_bits)
	{
		ft_is_0(tab, size_a, size_b, bit);
		return_in_b(tab, size_a, size_b, bit);
	}
	ft_negative_part_2(tab, size_a, negative);
	display_piles(tab, *size_a, *size_b);
}
