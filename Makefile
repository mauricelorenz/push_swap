NAME =		push_swap

SRC =		main.c \
			push_swap.c \
			ft_printf.c

OBJ =		$(SRC:.c=.o)

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re