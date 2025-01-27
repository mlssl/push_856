CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
SRCS = push_swap.c \
       ft_printf/ft_printf.c \
       ft_printf/ft_putnbr.c \
       ft_printf/ft_write_char.c \
       rules/push.c \
       rules/reverse.c \
       rules/rotate.c \
       rules/reverse_copy.c \
       rules/rotate_copy.c \
       rules/swap.c \
       utils/ft_atoi.c \
       utils/ft_atol.c \
       utils/ft_strlcpy.c \
       utils/ft_split.c \
       utils/utils.c \
       utils/count_mouvs_a.c \
       utils/count_mouvs_b.c \
       sort/sort_3or4.c \
       sort/sort_5.c \
       sort/sort_max.c \
       sort/radix.c \
       sort/binaire.c \
       error/error.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap.a
HEADER = ./includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
