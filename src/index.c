/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:17:11 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/31 11:50:31 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_index(t_map *map, t_index *index)
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
	if (!data->map)
		error(NOTHING_ERROR);
	get_index(data->map, &data->index);
	data->map_height = ft_mapsize(data->map);
	data->map_width = ft_strlen(data->map->row) - 1;
}
