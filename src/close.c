/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:32:24 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 20:18:43 by ihashimo         ###   ########.fr       */
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

void	error_free(t_base *data, int signal)
{
	ft_free_data(data);
	ft_printf("Error\n");
	if (signal == MINIMUM_ERROR)
		ft_printf("The map must contain ECP\n");
	if (signal == UNNESSESARY_ERROR)
		ft_printf("The map contains except ECP\n");
	if (signal == SURROUND_ERROR)
		ft_printf("The map must be surrounded by walls\n");
	if (signal == RECTANGLE_ERROR)
		ft_printf("The map must be rectangle\n");
	if (signal == UNABLETOGOAL_ERROR)
		ft_printf("The map not be able to goal\n");
	if (signal == IMAGE_ERROR)
		ft_printf("Images loading error\n");
	if (signal == MLX_ERROR)
		ft_printf("mlx error\n");
	exit(1);
}

void	error(int signal)
{
	ft_printf("Error\n");
	if (signal == AGUMENT_ERROR)
		ft_printf("Not enough arguments\n");
	if (signal == NOTHING_ERROR)
		ft_printf("Empty file\n");
	if (signal == EXTENTION_ERROR)
		ft_printf("Invalid file extension\n");
	if (signal == READ_ERROR)
		ft_printf("Failed to read\n");
	exit(1);
}
