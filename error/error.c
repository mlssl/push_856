/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:13 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:19 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(int **tab, int size_a)
{
	int	i;

	i = 1;
	while (i < size_a)
	{
		if (tab[i - 1][0] > tab[i][0])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != (void *)0)
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(int **tab, int size_a)
{
	int	i;
	int	j;
	int	test;

	i = 0;
	while (i < size_a)
	{
		test = tab[i][0];
		j = i + 1;
		while (j < size_a)
		{
			if (test == tab[j][0])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_char_error(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			if (argv[i][j + 1] == '\0' || (argv[i][j + 1] < '0' || argv[i][j
					+ 1] > '9'))
				return (-1);
			j++;
		}
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
