# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 22:19:07 by ihashimo          #+#    #+#              #
#    Updated: 2023/01/31 11:18:57 by ihashimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = libft
LIBFT_OBJ = $(LIBFT_DIR)/libft.a




MLX_DIR = minilibx-linux
MLX_OBJ = $(MLX_DIR)/libmlx.a
#MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Darwin.a

SRC = src/so_long.c \
	src/map.c \
	src/asset.c \
	src/move.c \
	src/move_up.c \
	src/move_down.c \
	src/move_right.c \
	src/move_left.c \
	src/index.c \
	src/draw.c \
	src/valid_map.c \
	src/valid_file.c \
	src/step.c \
	src/goal.c \
	src/close.c \
	src/free.c \
	src/init.c \
	src/rectangle.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -I minilibx-linux -I include -I libft/include -Wall -Wextra -Werror
XFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	gcc $(CFLAGS) -o $(NAME) $(LIBFT_OBJ) $(OBJ) $(MLX_OBJ) $(XFLAGS)

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