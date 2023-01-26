/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:44 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 21:12:29 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int keycode, t_base *data)
{
	if (keycode == KEY_ESC)
		end_game(data);
	else if (keycode == KEY_UP || keycode == KEY_W)
	{
		move_up(data->map, &data->index, &data->counts);
		data->dir_now = DIR_UP;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		move_left(data->map, &data->index, &data->counts);
		data->dir_now = DIR_LEFT;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		move_down(data->map, &data->index, &data->counts);
		data->dir_now = DIR_DOWN;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		move_right(data->map, &data->index, &data->counts);
		data->dir_now = DIR_RIGHT;
	}
	print_step(&data->counts);
	return (0);
}
