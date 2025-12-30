
NAME = libftprintf.a


CC = cc
CFLAGS = -Wall -Wextra -Werror


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	ft_printf.c ft_itoa_base.c put_nbr.c main.c

OBJS = $(SRCS:.c=.o)


INCLUDES = -I. -I$(LIBFT_DIR)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
