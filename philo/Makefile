CC		= cc
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= -g

NAME	= philo
INCLUDE = -I./include

SRC =	src/main.c \
		src/philo.c \
		src/util.c \
		src/ft_uatoi.c

OBJ =	$(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) $^ -o $@

$(OBJ): obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@

tests:
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) tests/pthread.c -o test_pthread

re: fclean all
clean:
	rm -rf obj
fclean: clean
	rm -f $(NAME)
.PHONY: all tests re clean fclean
