NAME =		libft.a

SRC =		ft_atoi.c \
			ft_atol.c \
			ft_printf.c \
			ft_isdigit.c

OBJ =		$(SRC:.c=.o)

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re