/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:32:24 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 14:27:33 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_base *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_data(data);
	exit(0);
}

void	end_game(t_base *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_data(data);
	exit(0);
}

void	error_free(t_base *data)
{
	ft_free_data(data);
	ft_printf("Error\n");
	exit(1);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}
