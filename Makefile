NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c push_swap.c parser.c \
		err_handle.c

OBJS = $(SRCS: .c=.o)

MYLIBFT = ./libft
LIBFT = $(MYLIBFT)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		@make -C $(MYLIBFT)

clean:
		rm -rf $(OBJS)
		@make -C $(MYLIBFT) clean

fclean: clean
		rm -rf $(NAME)
		@make -C $(MYLIBFT) fclean

re: fclean all

.PHONY: all clean fclean re