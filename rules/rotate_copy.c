/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:38:34 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_copy(int **tab, int size_a) //, int size_b
{
	int	buffer;
	int	i;

	if (size_a <= 1)
		return;
	buffer = tab[0][0];
	i = 0;
	while (i < size_a - 1)
	{
		tab[i][0] = tab[i + 1][0];
		i++;
	}
	tab[size_a - 1][0] = buffer;
	//affiche_tab(tab, size_a, size_b);
}

void	rb_copy(int **tab, int size_b) //int size_a,
{
	int	buffer;
	int	i;

	if (size_b <= 1)
		return;
	buffer = tab[0][1];
	i = 0;
	while (i < size_b - 1)
	{
		tab[i][1] = tab[i + 1][1];
		i++;
	}
	tab[size_b - 1][1] = buffer;
	//affiche_tab(tab, size_a, size_b);
}

void	rr_copy(int **tab, int size_a, int size_b)
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
	//affiche_tab(tab, size_a, size_b);
	buffer = tab[0][1];
	i = 0;
	while (i < size_b - 1)
	{
		tab[i][1] = tab[i + 1][1];
		i++;
	}
	tab[size_b - 1][1] = buffer;
	//affiche_tab(tab, size_a, size_b);
}
