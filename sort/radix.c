/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:40 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:54:43 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ENELVER
#include <stdio.h>
void	display_piles(int **tab, int size_a, int size_b)
{
	int	i;

	printf("Pile A: ");
	for (i = 0; i < size_a; i++)
		printf("%d ", tab[i][0]);
	printf("\nPile B: ");
	for (i = 0; i < size_b; i++)
		printf("%d ", tab[i][1]);
	printf("\n");
}

static void	step(int **tab, int *size_a, int *size_b)
{
	int	ref;
	int	len;
	int	div;
	int	i;
	int	size;
	int	save_size_init;

	i = 0;
	save_size_init = *size_a;
	size = save_size_init;
	len = ft_intlen(search_maxi(tab, *size_a));
	div = 1;
	
	// 1 - 100 - 10.000 - 1.000.000 - 100.000.000 - 1.000.000.000
	if (len % 2 != 0)
	{
		while (len >= 0)
		{
			size = save_size_init;
			if (len % 2 != 0)
			{
				ref = 0;
				while (ref <= 9)
				{
					//i = 0;
					while (is_ref_a(tab, ref, div, *size_a) == 1)
					//while (i < size)
					{
						
						if ((tab[0][0] / div) % 10 == ref)
						{
							pb(tab, size_a, size_b);
							//size--;
						}
						else if ((tab[0][0] / div) % 10 != ref)
						{
							// if (count_ra(tab, *size_a, ref, div) < count_rra(tab, *size_a, ref, div))
							// 	ra(tab, *size_a);
							// else
							// 	rra(tab, *size_a);
							ra(tab, *size_a);
							//i++;
						}
					}
					ref = search_ref_max(tab, ref, div, *size_a);
				}
				display_piles(tab, *size_a, *size_b);
			}
			
			else if (len % 2 == 0)
			{
				ref = 9;
				while (ref >= 0)
				{
					i = 0;
					printf("is ref : %d\n", is_ref_b(tab, ref, div, *size_b));
					while (i < size)
					//while (is_ref_b(tab, ref, div, *size_b) == 1)
					{
						if ((tab[0][1] / div) % 10 == ref)
						{
							pa(tab, size_a, size_b);
							size--;
						}
						else if ((tab[0][1] / div) % 10 != ref)
						{
							// if (count_rb(tab, *size_b, ref, div) < count_rrb(tab, *size_b, ref, div))
							// 	rb(tab, *size_b);
							// else
							// 	rrb(tab, *size_b);
							rb(tab, *size_b);
							i++;
						}
					}
					ref = search_ref_min(tab, ref, div, *size_b);
				}
				display_piles(tab, *size_a, *size_b);
			}
			div = div * 10;
			len--;
		}
	}
	
	// 10 - 1.000 - 100.000 - 10.000.000 - 100.000.000
	if (len % 2 == 0)
	{
		while (len >= 0)
		{
			// size = save_size_init;
			if (len % 2 == 0)
			{
				ref = 0;
				while (ref <= 9)
				{
					// i = 0;
					while (is_ref_a(tab, ref, div, *size_a) == 1)
					// while (i < size)
					{
						if ((tab[0][0] / div) % 10 == ref)
						{
							pb(tab, size_a, size_b);
							//size--;
						}
						else if ((tab[0][0] / div) % 10 != ref)
						{
							if (count_ra(tab, *size_a, ref, div) < count_rra(tab, *size_a, ref, div))
								ra(tab, *size_a);
							else
								rra(tab, *size_a);
							// ra(tab, *size_a);
							// i++;
						}
					}
					ref = search_ref_max(tab, ref, div, *size_a);
				}
				//display_piles(tab, *size_a, *size_b);
			}
			else if (len % 2 != 0)
			{
				ref = 9;
				while (ref >= 0)
				{
					// i = 0;
					while (is_ref_b(tab, ref, div, *size_b) == 1)
					//while (i < size)
					{
						if ((tab[0][1] / div) % 10 == ref)
						{
							pa(tab, size_a, size_b);
							//size--;
						}
						else
						{
							if (count_rb(tab, *size_b, ref, div) < count_rrb(tab, *size_b, ref, div))
								rb(tab, *size_b);
							else
								rrb(tab, *size_b);
							// rb(tab, *size_b);
							// i++;
						}
					}
					ref = search_ref_min(tab, ref, div, *size_b);
				}
				//display_piles(tab, *size_a, *size_b);
			}
			div = div * 10;
			len--;
		}
	}
	//display_piles(tab, *size_a, *size_b);
}
void	radix2(int **tab, int *size_a, int *size_b)
{
	step(tab, size_a, size_b);
}
