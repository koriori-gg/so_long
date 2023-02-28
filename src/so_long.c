/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:28 by ihashimo          #+#    #+#             */
/*   Updated: 2023/02/28 10:02:14 by ihashimo         ###   ########.fr       */
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
	ft_mlx_key_hook(&data);
	ft_mlx_hook(&data);
	ft_mlx_loop_hook(&data);
	ft_mlx_loop(&data);
}
