/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:28 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/24 21:46:17 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	iscomplete(t_count *counts)
{
	if (counts->collect == counts->current)
		counts->status = COMPLETE;
}

int	main_loop(t_base *data)
{
	iscomplete(&data->counts);
	draw_map(data);
	return (0);
}

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
	counts->walk = 0;
	counts->move = STAY;
}

void	init_struct(t_base *data)
{
	//TODO:他の要素の初期化する
	data->mlx = mlx_init();
	data->dir_now = DIR_DOWN;
	init_count(&data->counts);

}

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	*map;
	t_base	data;

	if (argc != 2)
	{
		ft_printf("error");
		exit(1);
	}
	init_struct(&data);
	input_map(&data.map, argv);
	init_index(&data);
	print_map(data.map);
	isvalid_map(&data);//TODO:validate_map(); 作成

	
	init_asset(&data);//TODO: 32の時ここで詰まる
	
	init_window(&data);

	mlx_key_hook(data.win, input_key, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
}