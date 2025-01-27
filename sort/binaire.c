/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:11:44 by mathildelau       #+#    #+#             */
/*   Updated: 2025/01/27 18:31:26 by mathildelau      ###   ########.fr       */
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

int	is_0_in_a(int **tab, int *size_a, int bit)
{
	int	i;
	i = 0;
	while (i < *size_a)
	{
		if (((tab[i][0] >> bit) & 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

int all_same_bit(int **tab, int *size_a, int bit)
{
    if (*size_a <= 1) // Si la pile a 0 ou 1 élément, tous les bits sont forcément identiques
        return (1);

    int first_bit = (tab[0][0] >> bit) & 1; // Récupère le bit de l'élément en haut de la pile

    for (int i = 1; i < *size_a; i++) // Parcours des autres éléments de la pile
    {
        if (((tab[i][0] >> bit) & 1) != first_bit) // Compare chaque bit avec le premier
            return (0); // Les bits sont différents
    }
    return (1); // Tous les bits sont identiques
}

void	return_in_b(int **tab, int *size_a, int *size_b, int bit)
{
	int	i;
	int	save;
	int	max_bits;
	int	max_value;

	i = 0;
	save = *size_b;
	max_value = search_maxi(tab, *size_a);
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	if (bit + 1 >= max_bits)
	{
		while (*size_b > 0)
			pa(tab, size_a, size_b);
	}
	else
	{
		while (i++ < save)
		{
			// if(i == save && (((tab[0][0] >> (bit + 1)) & 1) != 0) && (((tab[0][1] >> (bit + 1)) & 1) == 0))
			// 		rr(tab, *size_a, *size_b);
			// else 
			if (((tab[0][1] >> (bit + 1)) & 1) == 0)
				rb(tab, *size_b);
			else if (((tab[0][1] >> (bit + 1)) & 1) != 0)
				pa(tab, size_a, size_b);				
		}
	}
	if (is_sorted_b(tab, *size_b) == 1)
	{
		while (*size_b > 0)
			pa(tab, size_a, size_b);
	}
}

// void	radix_binary(int **tab, int *size_a, int *size_b)
// {
// 	int	max_bits;
// 	int	max_value;
// 	int	bit;
// 	int	i;
// 	int save;
// 	int	negative;

// 	negative = 0;
// 	i = 0;
// 	while (i < *size_a)
// 	{
// 		if (negative > tab[i][0])
// 			negative = tab[i][0];
// 		i++;
// 	}
// 	if (negative < 0)
// 	{
// 		negative = -negative;
// 		i = 0;
// 		while (i < *size_a)
// 		{
// 			tab[i][0] += negative ;
// 			i++;
// 		}
// 	}
// 	max_value = search_maxi(tab, *size_a);
// 	max_bits = 0;
// 	while ((max_value >> max_bits) != 0)
// 		max_bits++;
// 	bit = -1;
// 	while (++bit <= max_bits)
// 	{
// 		i = 0;
// 		if (all_same_bit(tab, size_a, bit) == 1)
//         {
//             bit++;
//             continue;
//         }
// 		save = *size_a;
// 		while (i++ < save)
// 		{
// 			write(1,"STEP BIT", 8);
// 			if (is_sorted(tab, *size_a) == 1)
// 				break;
// 			else if (((tab[0][0] >> bit) & 1) == 0)
// 			{
// 				if(i == save - 1 && (((tab[0][0] >> (bit + 1)) & 1) != 0))
// 					break;
// 				else
// 					pb(tab, size_a, size_b);
// 			}
// 			else
// 				ra(tab, *size_a);
// 		}
// 		return_in_b(tab, size_a, size_b, bit);
// 	}
// 	if (negative > 0)
// 	{
// 		i = 0;
// 		while (i < *size_a)
// 		{
// 			tab[i][0] -= negative; 
// 			i++;
// 		}
// 	}
// 	display_piles(tab, *size_a, *size_b);
// }

int there_is_0_ra(int **tab, int *size_a, int i, int bit)
{
	while (i < *size_a)
	{
		if (((tab[i][0] >> bit) & 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

int there_is_0_rra(int **tab, int *size_a, int i, int bit)
{
	while (i < *size_a)
	{
		if (((tab[*size_a - 1 - i][0] >> bit) & 1) == 0)
			return (1);
		i++;
	}
	return (0);
}
void	radix_binary(int **tab, int *size_a, int *size_b)
{
	int	max_bits;
	int	max_value;
	int	bit;
	int	i;
	int save;
	int	negative;

	negative = 0;
	i = 0;
	while (i < *size_a)
	{
		if (negative > tab[i][0])
			negative = tab[i][0];
		i++;
	}
	if (negative < 0)
	{
		negative = -negative;
		i = 0;
		while (i < *size_a)
		{
			tab[i][0] += negative ;
			i++;
		}
	}
	max_value = search_maxi(tab, *size_a);
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	bit = -1;
	while (++bit <= max_bits)
	{
		i = 0; 
		int ra_count = 0;
        int rra_count = 0;
		while (i < *size_a || there_is_0_ra(tab, size_a, i, bit) == 1)
		{
			if (((tab[i][0] >> bit) & 1) == 0)
            	ra_count++;
			i++;
		}
		save = *size_a;
		i = 0;
		while (i < save || there_is_0_rra(tab, size_a, i, bit) == 1)
		{
			if (((tab[save - 1 - i][0] >> bit) & 1) == 0)
            	rra_count++;
			i++;
		}
		ft_printf("ra : %d, rra : %d", ra_count, rra_count);
		i = 0;
		if (all_same_bit(tab, size_a, bit) == 1)
        {
            bit++;
            continue;
        }
		save = *size_a;
		while (i++ < save || ra_count > 0)
		{
			if (is_sorted(tab, *size_a) == 1)
				break;
			else if (((tab[0][0] >> bit) & 1) == 0)
			{
				if(i == save - 1 && (((tab[0][0] >> (bit + 1)) & 1) != 0))
					break;
				else
					pb(tab, size_a, size_b);
			}
			// else
			// 	ra(tab, *size_a);
			else
			{
				if (ra_count <= rra_count)
				{
					ra(tab, *size_a);
					ra_count--;
				}
				else
					rra(tab, *size_a);
			}
		}
		return_in_b(tab, size_a, size_b, bit);
	}
	if (negative > 0)
	{
		i = 0;
		while (i < *size_a)
		{
			tab[i][0] -= negative; 
			i++;
		}
	}
	display_piles(tab, *size_a, *size_b);
}
