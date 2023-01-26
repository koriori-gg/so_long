/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:07 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 17:28:38 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_base *data)
{
	t_map	*map_top;
	char	*str;
	int		i;
	int		j;

	map_top = data->map;
	j = 0;
	//TODO: Eに乗ってる時の画像考える
	while (map_top != NULL)
	{
		i = 0;
		str = map_top->row;
		while (str[i])
		{
			if (str[i] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->tile[0].img, i * data->image_width, j * data->image_height);
			else if (str[i] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->tile[1].img, i * data->image_width, j * data->image_height);
			else if (str[i] == 'P')
			{	if (data->counts.before == EXIT)
					mlx_put_image_to_window(data->mlx, data->win, data->player[data->dir_now][EXIT].img, i * data->image_width, j * data->image_height);
				else
					mlx_put_image_to_window(data->mlx, data->win, data->player[data->dir_now][OTHER].img, i * data->image_width, j * data->image_height);
			}
			else if (str[i] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->tile[data->counts.status].img, i * data->image_width, j * data->image_height);
			else if (str[i] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->tile[2].img, i * data->image_width, j * data->image_height);
			i++;
		}
		j++;
		map_top = map_top->next;
	}
}