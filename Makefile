CC = cc
CFLAGS = -Wextra -Werror -Wall -std=c99 -fno-sanitize=address
SRC = error_utils.c error.c init_stack_utils.c main.c operations_a.c operations_b.c operations_both.c sort_utils.c sort.c stack_utils.c
OBJS = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	echo compiling libft
	make -sC libft
	$(CC) $(CFLAGS) -Llibft/ -lft -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -sC libft

re: fclean all

.PHONY: all clean fclean re
