/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:07 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 20:42:40 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_base *data, char *str, int i, int j)
{
	int	width;
	int	height;

	width = i * data->img_width;
	height = j * data->img_height;
	if (str[i] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->tile_img[0], width, height);
	else if (str[i] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->tile_img[1], width, height);
	else if (str[i] == 'P' && data->counts.before == EXIT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_img[data->dir_now][EXIT], width, height);
	else if (str[i] == 'P' && data->counts.before == OTHER)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_img[data->dir_now][OTHER], width, height);
	else if (str[i] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->tile_img[data->counts.status], width, height);
	else if (str[i] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->tile_img[2], width, height);
}

void	draw_map(t_base *data)
{
	t_map	*map_top;
	char	*str;
	int		i;
	int		j;

	map_top = data->map;
	j = 0;
	while (map_top != NULL)
	{
		i = 0;
		str = map_top->row;
		while (str[i])
		{
			draw_image(data, str, i, j);
			i++;
		}
		j++;
		map_top = map_top->next;
	}
}
