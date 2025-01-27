/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:10:59 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(int **tab, int size_a) //, int size_b
{
	int	buffer;

	write(1, "sa\n", 3);
	if (size_a >= 2)
	{
		buffer = tab[0][0];
		tab[0][0] = tab[1][0];
		tab[1][0] = buffer;
	}
	//affiche_tab(tab, size_a, size_b);
}

void	sb(int **tab, int size_b) //int size_a,
{
	int	buffer;

	write(1, "sb\n", 3);
	if (size_b >= 2)
	{
		buffer = tab[0][1];
		tab[0][1] = tab[1][1];
		tab[1][1] = buffer;
	}
	//affiche_tab(tab, size_a, size_b);
}

void	ss(int **tab, int size_a, int size_b)
{
	write(1, "ss\n", 3);
	sa(tab, size_a); //, size_b
	sb(tab, size_b); //size_a,
	//affiche_tab(tab, size_a, size_b);
}
