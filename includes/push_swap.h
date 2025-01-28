/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:05:57 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:54 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

/*PRINTF*/
int		ft_printf(const char *format, ...);
int		ft_putchar(char c, int *len);
int		ft_putstr(char *str, int *len);
int		ft_putnbr_base(int nbr, char *base, int *len);
void	ft_unsigned(unsigned int n, int *len);
void	ft_pointer(unsigned long nbr, char *base, int *len);
void	ft_hexa(int nbr, char *base, int *len);

/*ERRORS*/
int		is_sorted(int **tab, int size_a);
int		ft_check_char_error(char **argv, int argc);
int		ft_check_int(char **argv);
int		ft_check_duplicate(int **tab, int size_a);

/*UTILS*/
size_t	ft_strlen(const char *s);
int		search_maxi(int **tab, int size_a);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	**ft_split(char *s, char c);
int		count_word(char *sentence, char set);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		ft_negative_part_1(int **tab, int *size_a);
void	ft_negative_part_2(int **tab, int *size_a, int negative);

/*OPERATORS*/
void	rra(int **tab, int size_a);
void	rrb(int **tab, int size_b);
void	rrr(int **tab, int size_a, int size_b);

void	ra(int **tab, int size_a);
void	rb(int **tab, int size_b);
void	rr(int **tab, int size_a, int size_b);

void	sa(int **tab, int size_a);
void	sb(int **tab, int size_b);
void	ss(int **tab, int size_a, int size_b);

void	pa(int	**tab, int *size_a, int *size_b);
void	pb(int	**tab, int *size_a, int *size_b);

/*SORTS*/
void	ft_sort_3(int **tab, int size_a); //, int size_b
void	ft_sort_4(int **tab, int *size_a, int *size_b);
void	ft_sort_5(int **tab, int *size_a, int *size_b);
void	radix_binary(int **tab, int *size_a, int *size_b);

#endif
