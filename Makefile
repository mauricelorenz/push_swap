NAME =			push_swap

SRC_DIR =		src/
SRC =			main.c \
				populate_stack.c \
				validate_input.c \
				sort_push_swap.c \
				sort_rotate.c

OBJ_DIR =		obj/
OBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR =		libft/
LIBFT = 		$(LIBFT_DIR)libft.a

CC =			cc

CFLAGS =		-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJ) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJ_DIR)
				$(MAKE) -C $(LIBFT_DIR) clean

fclean:			clean
				rm -f $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re