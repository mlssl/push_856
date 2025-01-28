/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:38:34 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 15:40:24 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(int **tab, int size_a)
{
	int	buffer;
	int	i;

	if (size_a <= 1)
		return ;
	write(1, "ra\n", 3);
	buffer = tab[0][0];
	i = 0;
	while (i < size_a - 1)
	{
		tab[i][0] = tab[i + 1][0];
		i++;
	}
	tab[size_a - 1][0] = buffer;
}

void	rb(int **tab, int size_b)
{
	int	buffer;
	int	i;

	if (size_b <= 1)
		return ;
	write(1, "rb\n", 3);
	buffer = tab[0][1];
	i = 0;
	while (i < size_b - 1)
	{
		tab[i][1] = tab[i + 1][1];
		i++;
	}
	tab[size_b - 1][1] = buffer;
}

void	rr(int **tab, int size_a, int size_b)
{
	int	buffer;
	int	i;

	write(1, "rr\n", 3);
	buffer = tab[0][0];
	i = 0;
	while (i < size_a - 1)
	{
		tab[i][0] = tab[i + 1][0];
		i++;
	}
	tab[size_a - 1][0] = buffer;
	buffer = tab[0][1];
	i = 0;
	while (i < size_b - 1)
	{
		tab[i][1] = tab[i + 1][1];
		i++;
	}
	tab[size_b - 1][1] = buffer;
}
