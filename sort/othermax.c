// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   othermax.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/07 12:45:00 by mlaussel          #+#    #+#             */
// /*   Updated: 2025/01/13 15:22:20 by mlaussel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/push_swap.h"

// TIRER LES UNITEES
static void	step1(int **tab, int *size_a, int *size_b)
{
	int	ref;
	int	i;
	int	size;

	i = 0;
	ref = 0;
	size = *size_a;
	while (ref <= 9)
	{
		i = 0;
		while (i < size)
		{
			if (tab[0][0] % 10 == ref)
			{
				pb(tab, size_a, size_b);
				size--;
			}
			else
			{
				ra(tab, *size_a); //, *size_b
				i++;
			}
		}
		ref++;
	}
}

// REMETTRE DANS LA PILE A
static void	step2_4(int **tab, int *size_a, int *size_b)
{
	while (*size_b > 0)
		pa(tab, size_a, size_b);
}

// TIRER LES DIZAINES
static void	step3(int **tab, int *size_a, int *size_b)
{
	int	ref;
	int	i;
	int	size;

	i = 0;
	ref = 0;
	size = *size_a;
	while (ref <= 9)
	{
		i = 0;
		while (i < *size_a)
		{
			if (tab[0][0] / 10 % 10 == ref)
			{
				pb(tab, size_a, size_b);
				size--;
			}
			else
			{
				ra(tab, *size_a); //, *size_b
				i++;
			}
		}
		ref++;
	}
}

static void	step5(int **tab, int *size_a, int *size_b)
{
	int	ref;
	int	i;
	int	max;
	int	len;
	int	div;
	int	size;

	max = search_maxi(tab, *size_a);
	len = ft_intlen(max);
	i = 0;
	ref = 0;
	div = 1;
	size = *size_a;
	while (len > 1)
	{
		div = div * 10;
		len--;
	}
	while (ref <= 9)
	{
		i = 0;
		while (i < *size_a)
		{
			if (tab[0][0] / div % 10 == ref)
			{
				pb(tab, size_a, size_b);
				size--;
			}
			else
			{
				ra(tab, *size_a); //, *size_b
				i++;
			}
		}
		ref++;
	}
}

void	radix(int **tab, int *size_a, int *size_b)
{
	int	ref;
	int	i;
	int	size;

	i = 0;
	ref = 0;
	size = *size_a;
	step1(tab, size_a, size_b);
	step2_4(tab, size_a, size_b);
	step3(tab, size_a, size_b);
	step2_4(tab, size_a, size_b);
	step5(tab, size_a, size_b);
	step2_4(tab, size_a, size_b);
}
