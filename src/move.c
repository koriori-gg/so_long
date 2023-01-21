/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:44 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/21 12:23:25 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_map *map, t_index *index, t_count *counts)
{
	t_map	*ptr;
	t_map	*dst;
	int		i;

	ptr = map;
	i = 0;
	while (ptr != NULL)
	{
		if (i == index->y)
			break;
		ptr = ptr->next;
		i++;
	}
	dst = ptr->next;
	if(dst->row[index->x] == '0')
	{
		dst->row[index->x] = 'P';
		ptr->row[index->x] = '0';
		index->y += 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	else if (dst->row[index->x] == 'C')
	{
		dst->row[index->x] = 'P';
		ptr->row[index->x] = '0';
		index->y += 1;
		counts->current += 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	// else if (dst->row[index->y] == 'E')
	//TODO: strchrにしてちっさい違いだけifにする
}

void	move_up(t_map *map, t_index *index, t_count *counts)
{
	t_map	*ptr;
	t_map	*dst;
	int		i;

	ptr = map;
	i = 0;
	while (ptr != NULL)
	{
		if (i + 1 == index->y)
			break;
		ptr = ptr->next;
		i++;
	}
	dst = ptr;
	ptr = ptr->next;
	if(dst->row[index->x] == '0')
	{
		dst->row[index->x] = 'P';
		ptr->row[index->x] = '0';
		index->y -= 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	else if (dst->row[index->x] == 'C')
	{
		dst->row[index->x] = 'P';
		ptr->row[index->x] = '0';
		index->y -= 1;
		counts->current +=1;	
		counts->walk += 1;
		counts->move = MOVE;
	}
	// else if (dst->row[index->y] == 'E')
}

void	move_right(t_map *map, t_index *index, t_count *counts)
{
	t_map	*ptr;
	int		i;

	ptr = map;
	i = 0;
	while (ptr != NULL)
	{
		if (i == index->y)
			break;
		ptr = ptr->next;
		i++;
	}
	if(ptr->row[index->x + 1] == '0')
	{
		ptr->row[index->x + 1] = 'P';
		ptr->row[index->x] = '0';
		index->x += 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	else if (ptr->row[index->x + 1] == 'C')
	{
		ptr->row[index->x + 1] = 'P';
		ptr->row[index->x] = '0';
		index->x += 1;
		counts->current += 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	// else if (ptr->row[data->index.x + 1] == 'E')

}

void	move_left(t_map *map, t_index *index, t_count *counts)
{
	t_map	*ptr;
	int		i;

	ptr = map;
	i = 0;
	while (ptr != NULL)
	{
		if (i == index->y)
			break;
		ptr = ptr->next;
		i++;
	}
	if(ptr->row[index->x - 1] == '0')
	{
		ptr->row[index->x - 1] = 'P';
		ptr->row[index->x] = '0';
		index->x -= 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	else if (ptr->row[index->x - 1] == 'C')
	{
		ptr->row[index->x - 1] = 'P';
		ptr->row[index->x] = '0';
		index->x -= 1;
		counts->current += 1;
		counts->walk += 1;
		counts->move = MOVE;
	}
	// else if (ptr->row[data->index.x + 1] == 'E')

}
int	input_key(int keycode, t_base *data)
{
	//printf("%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == KEY_UP || keycode == KEY_W)
	{
		printf("up\n");
		move_up(data->map, &data->index, &data->counts);
		data->dir_now = DIR_UP;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		printf("left\n");
		move_left(data->map, &data->index, &data->counts);
		data->dir_now = DIR_LEFT;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		printf("down\n");
		move_down(data->map, &data->index, &data->counts);
		data->dir_now = DIR_DOWN;
	}

	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		printf("right\n");
		move_right(data->map, &data->index, &data->counts);
		data->dir_now = DIR_RIGHT;
	}

	else
		printf("hoge\n");
	//printf("index : x : %d y : %d\n", data->index.x, data->index.y);
	print_step(&data->counts);
	return (0);
}