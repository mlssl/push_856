/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:17:00 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 16:10:51 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_negative_part_1(int **tab, int *size_a)
{
	int	i;
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
			tab[i][0] += negative;
			i++;
		}
	}
	return (negative);
}

void	ft_negative_part_2(int **tab, int *size_a, int negative)
{
	int	i;

	i = 0;
	if (negative > 0)
	{
		while (i < *size_a)
		{
			tab[i][0] -= negative;
			i++;
		}
	}
}
