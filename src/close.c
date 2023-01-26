#include "so_long.h"

void	end_game(t_base *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_data(data);
	exit(0);
}

void	error_free(t_base *data)
{
	ft_free_data(data);
	ft_printf("error\n");
	exit(1);
}

void	error()
{
	write(1,"error\n",6);
	exit(1);
}