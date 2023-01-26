#include "so_long.h"

void	end_game(t_base *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_data(data);
	exit(0);
}

void	error(t_base *data)
{
	//mlx_destroy_window(data->mlx, data->win);//TODO:windowがない状態であるとsegfになる->消す：必要になる箇所がないか確認
	ft_free_data(data);
	ft_printf("error\n");
	exit(1);
}