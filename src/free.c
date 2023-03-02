/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:49:17 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 14:58:24 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *map)
{
	t_map	*ptr;

	while (map != NULL)
	{
		ptr = map;
		map = map->next;
		free(ptr->row);
		free(ptr);
	}
}

static void	free_mlx(t_base *data)
{
	free(data->mlx);
}

static void	free_asset(t_base *data)
{
	mlx_destroy_image(data->mlx, data->player_img[DIR_DOWN][0]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_DOWN][1]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_UP][0]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_UP][1]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_RIGHT][0]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_RIGHT][1]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_LEFT][0]);
	mlx_destroy_image(data->mlx, data->player_img[DIR_LEFT][1]);
	mlx_destroy_image(data->mlx, data->tile_img[0]);
	mlx_destroy_image(data->mlx, data->tile_img[1]);
	mlx_destroy_image(data->mlx, data->tile_img[2]);
	mlx_destroy_image(data->mlx, data->tile_img[3]);
	mlx_destroy_image(data->mlx, data->tile_img[4]);
}

void	ft_free_data(t_base *data)
{
	ft_free_map(data->map);
	free_asset(data);
	free_mlx(data);
}
