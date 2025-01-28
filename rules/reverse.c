/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:38:42 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 15:40:03 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(int **tab, int size_a)
{
	int	buffer;
	int	i;

	write(1, "rra\n", 4);
	buffer = tab[size_a - 1][0];
	i = size_a - 1;
	while (i > 0)
	{
		tab[i][0] = tab[i - 1][0];
		i--;
	}
	tab[0][0] = buffer;
}

void	rrb(int **tab, int size_b)
{
	int	buffer;
	int	i;

	write(1, "rrb\n", 4);
	buffer = tab[size_b - 1][1];
	i = size_b - 1;
	while (i > 0)
	{
		tab[i][1] = tab[i - 1][1];
		i--;
	}
	tab[0][1] = buffer;
}

void	rrr(int **tab, int size_a, int size_b)
{
	write(1, "rrr\n", 4);
	rra(tab, size_a);
	rrb(tab, size_b);
}
