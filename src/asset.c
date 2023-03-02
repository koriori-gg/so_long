/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:14 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 14:58:18 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_xpm_to_image(t_base *data, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin("textures/32/", str);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->img_width,
			&data->img_height);
	free(path);
	if (!img)
		error_free(data, IMAGE_ERROR);
	return (img);
}

void	init_asset(t_base *data)
{
	data->player_img[DIR_DOWN][0] = ft_xpm_to_image(data, "player_front.xpm");
	data->player_img[DIR_DOWN][1] = ft_xpm_to_image(data, "player_front1.xpm");
	data->player_img[DIR_UP][0] = ft_xpm_to_image(data, "player_back.xpm");
	data->player_img[DIR_UP][1] = ft_xpm_to_image(data, "player_back1.xpm");
	data->player_img[DIR_RIGHT][0] = ft_xpm_to_image(data, "player_right.xpm");
	data->player_img[DIR_RIGHT][1] = ft_xpm_to_image(data, "player_right1.xpm");
	data->player_img[DIR_LEFT][0] = ft_xpm_to_image(data, "player_left.xpm");
	data->player_img[DIR_LEFT][1] = ft_xpm_to_image(data, "player_left1.xpm");
	data->tile_img[0] = ft_xpm_to_image(data, "zero.xpm");
	data->tile_img[1] = ft_xpm_to_image(data, "one.xpm");
	data->tile_img[2] = ft_xpm_to_image(data, "collect.xpm");
	data->tile_img[3] = ft_xpm_to_image(data, "exit_before.xpm");
	data->tile_img[4] = ft_xpm_to_image(data, "exit_after.xpm");
}
