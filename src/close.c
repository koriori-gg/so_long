#include "so_long.h"

void	end_game(t_base *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_all(data);
	exit(0);
}

void	error(t_base *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_all(data);
	ft_printf("error\n");
	exit(1);
}