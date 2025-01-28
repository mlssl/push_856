/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:12:37 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:28 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	**malloc_tab(int argc)
{
	int	**tab;
	int	i;
	int	cols;

	i = 0;
	cols = 2;
	tab = malloc((argc) * sizeof(int *));
	if (tab == NULL)
		return (NULL);
	while (i < argc)
	{
		tab[i] = malloc(cols * sizeof(int));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}

static int	**init_tab(int **tab, char **argv, int argc, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < argc)
		{
			tab[j][0] = ft_atoi(argv[i]);
			i++;
			j++;
		}
	}
	else if (i == 1)
	{
		while (i <= argc)
		{
			tab[j][0] = ft_atoi(argv[i]);
			i++;
			j++;
		}
	}
	return (tab);
}

static void	choice_sort(int **tab, int size_a, int size_b, int argc)
{
	if (argc == 2 && tab[0][0] > tab[1][0] && is_sorted(tab, size_a) != 1)
		sa(tab, size_a);
	else if (argc == 3 && is_sorted(tab, size_a) != 1)
		ft_sort_3(tab, size_a);
	else if (argc == 4 && is_sorted(tab, size_a) != 1)
		ft_sort_4(tab, &size_a, &size_b);
	else if (argc == 5 && is_sorted(tab, size_a) != 1)
		ft_sort_5(tab, &size_a, &size_b);
	else if (argc > 5 && is_sorted(tab, size_a) != 1)
		radix_binary(tab, &size_a, &size_b);
}

/*PENSER A METTRE LA SORTIE ERREUR SUR -1
+ REVERIFIER SI DEMANDER DANS LE SUJET*/
int	main(int argc, char **argv)
{
	int	**tab;
	int	size_a;
	int	size_b;
	int	i;

	i = 1;
	argc = argc - 1;
	if (argc == 1)
	{
		argc = count_word(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	size_a = argc;
	size_b = 0;
	if (ft_check_char_error(argv, argc) == -1 || ft_check_int(argv) == -1)
		return (write(1, "Error\n", 6));
	tab = malloc_tab(argc);
	if (argc > 1)
		tab = init_tab(tab, argv, argc, i);
	if (ft_check_duplicate(tab, size_a) == -1)
		return (write(1, "Error\n", 6));
	choice_sort(tab, size_a, size_b, argc);
	free(tab);
	if (tab != NULL)
		tab = NULL;
}
