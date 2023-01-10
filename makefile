NAME = so_long

LIBFT_DIR = libft
LIBFT_OBJ = $(LIBFT_DIR)/libft.a




MLX_DIR = minilibx-linux
MLX_OBJ = $(MLX_DIR)/libmlx.a
#MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Darwin.a

SRC = src/so_long.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -I minilibx-linux -I include -I libft/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	gcc $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(MLX_OBJ)

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

$(LIBMLX_OBJ):
	make -C $(LIBMLX_DIR)


clean:
	$(RM) $(OBJ)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PONEY: all clean fclean re