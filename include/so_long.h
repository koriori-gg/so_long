/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:19:22 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 17:17:37 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "mlx_int.h"
#include "mlx.h"

# define KEY_PRESS		2

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_UP			65362
# define KEY_LEFT		65361
# define KEY_DOWN		65364
# define KEY_RIGHT		65363

# define DIR_DOWN		0
# define DIR_UP			1
# define DIR_RIGHT		2
# define DIR_LEFT		3

# define INCOMPLETE		3
# define COMPLETE		4

# define MOVE			1
# define STAY			0

# define PLAYING		1
# define FINISH			0

# define EXIT			1
# define OTHER			0

typedef struct	s_map {
	char			*row;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

typedef struct	s_image {
	void	*img;
	char	*path;
	int		width;//iran
	int		height;//iran
}				t_image;

typedef struct s_index
{
	int	x;
	int	y;
}				t_index;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_count
{
	size_t	collect;
	size_t	current;
	int		status;//FLG管理したい
	int		play;
	size_t	step;
	int		move;
	int		before;
}				t_count;


typedef struct	s_base {
	void	*mlx;
	void	*win;
	int		map_height;
	int		map_width;
	t_index	index;
	t_map	*map;
	t_image	player[4][3];
	t_image	tile[5];
	int		image_height;
	int		image_width;
	t_data	img;
	int		dir_now;
	t_count	counts;
}				t_base;
//init
void	init_window(t_base *data);
void	init_count(t_count *counts);
void	init_struct(t_base *data);
//map
t_map	*ft_mapnew(char *str);
int		ft_mapsize(t_map *map);
void	ft_mapadd_back(t_map **map, t_map *new);
void	input_map(t_map **map, char **argv);
void	print_map(t_map *map);
//move
int	input_key(int keycode, t_base *data);
//asset
void	init_asset(t_base *data);
//index
void	init_index(t_base *data);
//draw
void	draw_map(t_base *data);
//valid
void	isvalid_map(t_base *data);
//step
void	print_step(t_count *counts);
//valid_file
void	validate_file(char *arg);
//valid_map
void	contains_unnecessary(t_base *data, char *chars);
//goal
void	able_to_goal(t_base *data);
//close
void	end_game(t_base *data);
void	error_free(t_base *data);
void	error();
//free
void	ft_free_data(t_base *data);
void	ft_free_map(t_map *map);
//move_utils
void	move_up(t_map *map, t_index *index, t_count *counts);
void	move_down(t_map *map, t_index *index, t_count *counts);
void	move_left(t_map *map, t_index *index, t_count *counts);
void	move_right(t_map *map, t_index *index, t_count *counts);

#endif