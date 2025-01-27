/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:13 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 17:12:53 by mathildelau      ###   ########.fr       */
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
int	is_sorted_b(int **tab, int size_b)
{
	int	i;

	i = 1;
	while (i < size_b)
	{
		if (tab[i - 1][1] > tab[i][1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_int_min_max(char **argv, int argc)
{
	int i;

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

int ft_check_char_error(char **argv, int argc)
{
    int i;
    int j;

    i = 1;  // Commence à 1 car argv[0] est le nom du programme
    while (i < argc)
    {
        j = 0;

        // Si un signe "-" est trouvé au début du nombre, vérifier que les caractères suivants sont des chiffres
        if (argv[i][j] == '-')
        {
            // Si "-" est le seul caractère ou est suivi de non-chiffre, c'est une erreur
            if (argv[i][j + 1] == '\0' || (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
                return (-1);
            j++;  // On passe à l'examen des chiffres après le "-"
        }

        // Vérifie que tous les caractères suivants sont des chiffres
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')  // Si c'est un non-chiffre
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

