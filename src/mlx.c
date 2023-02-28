/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:04:19 by ihashimo          #+#    #+#             */
/*   Updated: 2023/02/28 10:04:20 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_key_hook(t_base *data)
{
	if (!mlx_key_hook(data->win, input_key, data))
		error_free(data, MLX_ERROR);
}

void	ft_mlx_hook(t_base *data)
{
	if (!mlx_hook(data->win, RED_CLOSS, 0, &close_game, data))
		error_free(data, MLX_ERROR);
}

void	ft_mlx_loop_hook(t_base *data)
{
	if (!mlx_loop_hook(data->mlx, main_loop, data))
		error_free(data, MLX_ERROR);
}

void	ft_mlx_loop(t_base *data)
{
	if (!mlx_loop(data->mlx))
		error_free(data, MLX_ERROR);
}

void	ft_mlx_destroy_window(t_base *data)
{
	if (!mlx_destroy_window(data->mlx, data->win))
		error_free(data, MLX_ERROR);
}
