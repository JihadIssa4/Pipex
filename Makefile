NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c pipex_utils.c ft_split.c free.c finding_path.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re