/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:28 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 20:45:47 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_base	data;

	if (argc != 2)
		error(AGUMENT_ERROR);
	validate_file(argv[1]);
	init_struct(&data, argv);
	mlx_key_hook(data.win, input_key, &data);
	mlx_hook(data.win, RED_CLOSS, 0, &close_game, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
}
