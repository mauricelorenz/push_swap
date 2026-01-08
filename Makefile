NAME =			push_swap
NAME_BONUS =	checker

SRC_DIR =		src/
SRC =			main.c \
				populate_stack.c \
				set_rank.c \
				sort_push_swap.c \
				sort_rotate.c \
				sort_utils.c \
				sort.c \
				validate_input.c

SRC_BONUS =		main_bonus.c \
				check_sorting_bonus.c \
				populate_stack.c \
				set_rank.c \
				sort_push_swap.c \
				sort_rotate.c \
				sort_utils.c \
				validate_input.c

OBJ_DIR =		obj/
OBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BONUS =		$(addprefix $(OBJ_DIR), $(SRC_BONUS:.c=.o))

LIBFT_DIR =		libft/
LIBFT = 		$(LIBFT_DIR)libft.a

CC =			cc

CFLAGS =		-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJ) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus:			$(OBJ_BONUS) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

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
				rm -f $(NAME_BONUS)
				$(MAKE) -C $(LIBFT_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re