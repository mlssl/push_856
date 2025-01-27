/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:05:57 by mlaussel          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:27 by mathildelau      ###   ########.fr       */
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
int	is_sorted(int **tab, int size_a);
int	is_sorted_b(int **tab, int size_b);
int	ft_check_char_error(char **argv, int argc);
int	ft_check_int_min_max(char **argv, int argc);
int	ft_check_duplicate(int **tab, int size_a);

/*UTILS*/
size_t	ft_strlen(const char *s);
int		ft_intlen(int nb);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	**ft_split(char *s, char c);
int		count_word(char *sentence, char set);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	    **malloc_tab(int argc);

int	search_ref_min(int **tab, int ref, int div, int size);
int	search_ref_max(int **tab, int ref, int div, int size);

int	is_ref_b(int **tab, int ref, int div, int size_b);
int	is_ref_a(int **tab, int ref, int div, int size_a);

void	copy_a(int **tab, int **tab_copy, int size_a);
int	count_ra(int **tab, int size_a, int ref, int div);
int count_rra(int **tab, int size_a, int ref, int div);
int	count_ra_binaire(int **tab, int size_a, int bit);
int	count_rra_binaire(int **tab, int size_a, int bit);

void	copy_b(int **tab, int **tab_copy, int size_b);
int count_rb(int **tab, int size_b, int ref, int div);
int count_rrb(int **tab, int size_b, int ref, int div);
int count_rb_binaire(int **tab, int size_b, int bit);
int count_rrb_binaire(int **tab, int size_b, int bit);


/*OPERATORS*/
void	rra(int **tab, int size_a);
void	rrb(int **tab, int size_b);
void	rra_copy(int **tab, int size_a);
void	rrb_copy(int **tab, int size_b);
void	rrr(int **tab, int size_a, int size_b);
void	ra(int **tab, int size_a);
void	rb(int **tab, int size_b);
void	ra_copy(int **tab, int size_a);
void	rb_copy(int **tab, int size_b);
void	rr(int **tab, int size_a, int size_b);
void	sa(int **tab, int size_a);
void	sb(int **tab, int size_b);
void	ss(int **tab, int size_a, int size_b);
void	pa(int	**tab, int *size_a, int *size_b);
void	pb(int	**tab, int *size_a, int *size_b);

//void	//affiche_tab(int **tab, int size_a, int size_b);
/*SORTS*/
void	ft_sort_max(int **tab, int *size_a, int *size_b);
void	ft_sort_3(int **tab, int size_a); //, int size_b
void	ft_sort_4(int **tab, int *size_a, int *size_b);
void	ft_sort_5(int **tab, int *size_a, int *size_b);
void	radix(int **tab, int *size_a, int *size_b);
void	radix2(int **tab, int *size_a, int *size_b);
int		search_maxi(int **tab, int size_a);
void    radix_binary(int **tab, int *size_a, int *size_b);

#endif
