/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:14 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 16:45:57 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_xpm_to_image(t_base *data, char *str)
{
	char	*path;
	void	*img;

	path =ft_strjoin("textures/32/", str);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->image_width, &data->image_height);
	free(path);
	if (!img)
		error_free(data);
	return (img);
}

void	init_asset(t_base *data)
{
	data->player[DIR_DOWN][0].img = ft_xpm_to_image(data, "player_front.xpm");
	data->player[DIR_DOWN][1].img = ft_xpm_to_image(data, "player_front1.xpm");
	data->player[DIR_DOWN][2].img = ft_xpm_to_image(data, "player_front2.xpm");
	data->player[DIR_UP][0].img = ft_xpm_to_image(data, "player_back.xpm");
	data->player[DIR_UP][1].img = ft_xpm_to_image(data, "player_back1.xpm");
	data->player[DIR_UP][2].img = ft_xpm_to_image(data, "player_back2.xpm");
	data->player[DIR_RIGHT][0].img  = ft_xpm_to_image(data, "player_right.xpm");
	data->player[DIR_RIGHT][1].img  = ft_xpm_to_image(data, "player_right1.xpm");
	data->player[DIR_RIGHT][2].img  = ft_xpm_to_image(data, "player_right2.xpm");
	data->player[DIR_LEFT][0].img  = ft_xpm_to_image(data, "player_left.xpm");
	data->player[DIR_LEFT][1].img  = ft_xpm_to_image(data, "player_left1.xpm");
	data->player[DIR_LEFT][2].img  = ft_xpm_to_image(data, "player_left2.xpm");
	data->tile[0].img  = ft_xpm_to_image(data, "zero.xpm");
	data->tile[1].img  = ft_xpm_to_image(data, "one.xpm");
	data->tile[2].img  = ft_xpm_to_image(data, "collect.xpm");
	data->tile[3].img  = ft_xpm_to_image(data, "exit_before.xpm");
	data->tile[4].img  = ft_xpm_to_image(data, "exit_after.xpm");

}