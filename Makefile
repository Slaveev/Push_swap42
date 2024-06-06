CC = cc
CFLAGS = -Wextra -Werror -Wall -std=c99 -fno-sanitize=address
SRC = error_utils.c error.c init_stack_utils.c main.c operations_a.c operations_b.c operations_both.c sort_utils.c sort.c stack_utils.c utils.c
OBJS = $(SRC:.c=.o)
NAME = push_swap
LIBS = -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
