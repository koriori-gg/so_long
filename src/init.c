/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:59:38 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 17:15:04 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_base *data)
{
	//ここの構造体変えられる
	//TODO:ここで使ってるimgっていう構造体の見直し
	//TODO:命名の見直し
	//TODO:ほんまに必要かの見直し
	data->win = mlx_new_window(data->mlx, data->image_width * data->map_width, data->image_height * data->map_height, "so_long");
	data->img.img = mlx_new_image(data->mlx,  data->image_width * data->map_width, data->image_height * data->map_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	init_count(t_count *counts)
{
	counts->collect = 0;
	counts->current = 0;
	counts->status = INCOMPLETE;
	counts->play = PLAYING;
	counts->step = 0;
	counts->move = STAY;
	counts->before = OTHER;
}

void	init_struct(t_base *data)
{
	//TODO:他の要素の初期化する
	data->mlx = mlx_init();
	data->dir_now = DIR_DOWN;
	init_count(&data->counts);

}