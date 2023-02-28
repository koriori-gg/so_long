/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:07 by ihashimo          #+#    #+#             */
/*   Updated: 2023/02/28 10:05:10 by ihashimo         ###   ########.fr       */
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
		ft_mlx_put_image_to_window(data, data->tile[0].img, width, height);
	else if (str[i] == '1')
		ft_mlx_put_image_to_window(data, data->tile[1].img, width, height);
	else if (str[i] == 'P' && data->counts.before == EXIT)
		ft_mlx_put_image_to_window(data,
			data->player[data->dir_now][EXIT].img, width, height);
	else if (str[i] == 'P' && data->counts.before == OTHER)
		ft_mlx_put_image_to_window(data,
			data->player[data->dir_now][OTHER].img, width, height);
	else if (str[i] == 'E')
		ft_mlx_put_image_to_window(data,
			data->tile[data->counts.status].img, width, height);
	else if (str[i] == 'C')
		ft_mlx_put_image_to_window(data, data->tile[2].img, width, height);
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
