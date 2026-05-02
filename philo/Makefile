CC		= cc
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= -g

NAME	= philo
INCLUDE = -I./include

SRC =	src/philo.c \
		src/philo_actions.c \
		src/philo_forks.c \
		src/util.c \
		src/ft_uatoi.c
MAIN =	src/main.c

OBJ =	$(SRC:src/%.c=obj/%.o) \
		$(MAIN:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) $^ -o $@

$(OBJ): obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@

tests:
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) tests/pthread.c -o test_pthread
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) tests/mutex.c -o test_mutex
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) src/ft_uatoi.c src/util.c tests/time.c -o test_time
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) $(SRC) tests/one_philo.c -o test_one_philo

re: fclean all
clean:
	rm -rf obj
fclean: clean
	rm -f $(NAME)
.PHONY: all tests re clean fclean
