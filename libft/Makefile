NAME =			libft.a

SRC_DIR =		src/
SRC =			ft_atoi.c \
				ft_atol.c \
				ft_isdigit.c \
				ft_putendl_fd.c \
				ft_split.c \
				ft_strncmp.c

OBJ_DIR =		obj/
OBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC =			cc

CFLAGS =		-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJ_DIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re