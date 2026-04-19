CC		= cc
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= -g

NAME	= philo
INCLUDE = -I./include

SRC =	src/main.c \
		src/philo.c \
		src/util.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -o $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $^