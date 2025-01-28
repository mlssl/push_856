NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes

RM      = rm -f

SRCS = push_swap.c \
       rules/push.c \
       rules/reverse.c \
       rules/rotate.c \
       rules/swap.c \
       utils/ft_atoi.c \
       utils/ft_atol.c \
       utils/ft_strlcpy.c \
       utils/ft_split.c \
       utils/utils.c \
       utils/negative.c \
       sort/sort_3or4.c \
       sort/sort_5.c \
       sort/binaire.c \
       ft_printf/ft_printf.c \
       ft_printf/ft_putnbr.c \
       ft_printf/ft_write_char.c \
       error/error.c

OBJS = $(SRCS:.c=.o)

HEADER = ./includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re make
