/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:28 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 00:02:51 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	iscomplete(t_count *counts)
{
	if (counts->collect == counts->current)
		counts->status = COMPLETE;
}

void	isgoal(t_base *data)
{
	if (data->counts.play == FINISH)
		end_game(data);
}

int	main_loop(t_base *data)
{
	iscomplete(&data->counts);
	draw_map(data);
	isgoal(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_base	data;

	if (argc != 2)
		error();
	validate_file(argv[1]);
	init_struct(&data);
	input_map(&data.map, argv);
	init_index(&data);
	isvalid_map(&data);
	init_asset(&data);
	init_window(&data);
	mlx_key_hook(data.win, input_key, &data);
	mlx_hook(data.win, RED_CLOSS, 0, &close_game, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
}
