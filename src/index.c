/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:11 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/21 12:23:46 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_index(t_map *map, t_index *index)
{
	int	i;
	int	j;

	i = 0;
	while (map != NULL)
	{
		j = 0;
		while ((map->row)[j])
		{
			if ((map->row)[j] == 'P')
			{
				index->x = j;
				index->y = i;
				return ;
			}
			j++;
		}
		i++;
		map = map->next;
	}
}

void	init_index(t_base *data)
{
	get_index(data->map, &data->index);
	data->map_height = ft_mapsize(data->map);
	data->map_width = ft_strlen(data->map->row) - 1;//改行分　//TODO: ここで調整するか考える必要あり
	//printf("index : x : %d y : %d\n", data->index.x, data->index.y);
	//TODO: image heightがおかしいから見直し
	//printf("map height %d   width %d", data->map_height, data->map_width);
	//printf("img height %d   width %d", data->image_height, data->image_width);
}