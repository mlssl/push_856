/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:23 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 15:43:01 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	search_maxi(int **tab, int size_a)
{
	int	max;
	int	i;

	i = 1;
	max = tab[0][0];
	while (i < size_a)
	{
		if (tab[i][0] > max)
			max = tab[i][0];
		i++;
	}
	return (max);
}
