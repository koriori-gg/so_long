#include "so_long.h"

void	ft_free_map(t_map *map)
{
	t_map	*ptr;
	while (map != NULL)
	{
		ptr = map;
		map = map->next;
		//TODO: rowと分けてやらなあかんか確認
		free(ptr);
	}
}

void	ft_free_data(t_base *data)
{
	ft_free_map(data->map);
}