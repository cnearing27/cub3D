NAME = cub3D
NAME_BONUS = cub3D_bonus

SRCS	= 	./src/main.c \
			./src/init.c \
			./src/key_actions.c \
			./src/key_handler.c \
			./src/check_walls.c \
			./src/check_rows.c \
			./src/check_map.c \
			./src/import_map.c \
			./src/open_map.c \
			./src/parse_map.c \
			./src/utils.c \
			./src/add_walls.c \
			./src/walls_casting.c

SRC_BONUS =	./srcs_bonus/doors_bonus.c \
			./srcs_bonus/init_bonus.c \
			./srcs_bonus/key_actions_bonus.c \
			./srcs_bonus/key_handler_bonus.c \
			./srcs_bonus/key_rotate_bonus.c \
			./srcs_bonus/main_bonus.c \
			./srcs_bonus/check_walls_bonus.c \
			./srcs_bonus/check_rows_bonus.c \
			./srcs_bonus/check_map_bonus.c \
			./srcs_bonus/import_map_bonus.c \
			./srcs_bonus/open_map_bonus.c \
			./srcs_bonus/parse_map_bonus.c \
			./srcs_bonus/minimap_bonus.c \
			./srcs_bonus/mouse_bonus.c \
			./srcs_bonus/utils_bonus.c \
			./srcs_bonus/add_walls_bonus.c \
			./srcs_bonus/walls_casting_bonus.c


OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ_DIR			= src/
OBJ_BONUS_DIR	= srcs_bonus/

HEADER = ./src/cub3d.h
HEADER_BONUS = ./srcs_bonus/cub3d_bonus.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

MLX_FLAGS = -lmlx -L ./miniLibx -framework OpenGL -framework AppKit

LIBDIR		= libft

LIBFT_LIB	= $(LIBDIR)/libft.a

LIB			= -L$(LIBDIR) -lft

GNL			= get_next_line/get_next_line.a

MLX_DIR		= miniLibx

all: $(NAME)

$(NAME): $(OBJ)
			make -C $(LIBDIR)
			make -C get_next_line
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(LIBFT_LIB) $(GNL) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o:	$(OBJ_DIR)%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
			make -C $(LIBDIR)
			make -C get_next_line
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(LIBFT_LIB) $(GNL) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJ_BONUS_DIR)%.o:	$(OBJ_BONUS_DIR)%.c $(HEADER_BONUS)
						$(CC) $(CFLAGS) -c $< -o $@

clean:
		make clean -C $(LIBDIR)
		make clean -C get_next_line
		make clean -C $(MLX_DIR)
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus