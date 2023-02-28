/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:59:38 by ihashimo          #+#    #+#             */
/*   Updated: 2023/02/28 10:02:50 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_base *data)
{
	data->win = mlx_new_window(data->mlx, data->img_width * data->map_width,
			data->img_height * data->map_height, "so_long");
	if (!data->win)
		error_free(data, MLX_ERROR);
}

static void	init_count(t_count *counts)
{
	counts->collect = 0;
	counts->current = 0;
	counts->status = INCOMPLETE;
	counts->play = PLAYING;
	counts->step = 0;
	counts->move = STAY;
	counts->before = OTHER;
}

void	init_struct(t_base *data, char **argv)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_free(data, MLX_ERROR);
	data->dir_now = DIR_DOWN;
	init_count(&data->counts);
	input_map(&data->map, argv);
	init_index(data);
	isvalid_map(data);
	init_asset(data);
	init_window(data);
}
