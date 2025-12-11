NAME	= push_swap

cc		= cc
CFLAGS  = -Wall -Wextra -Werror

SRCS	= main.c push_swap.c parser.c \
		err_handle.c ex_func.c

OBJS	= $(SRCS:.c=.o)

MYLIBFT = ./libft
LIBFT	= $(MYLIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(MYLIBFT)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MYLIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MYLIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
