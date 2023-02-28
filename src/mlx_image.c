/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:04:10 by ihashimo          #+#    #+#             */
/*   Updated: 2023/02/28 10:04:11 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_put_image_to_window(t_base *data,
		void *img, int width, int height)
{
	if (!mlx_put_image_to_window(data->mlx, data->win, img, width, height))
		error_free(data, MLX_ERROR);
}
