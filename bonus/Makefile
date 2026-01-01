
NAME = libftprintf.a


CC = cc
CFLAGS = -Wall -Wextra


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	data.c data_utils.c data_utils_two.c \
		ft_printf.c mtx_args.c  check_comb.c \
		new_values.c new_value_utils.c case_precision.c \
		case_bonus.c minus_width_case.c case_precision_utils.c \
		check_valid_args.c main_bonus.c

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
