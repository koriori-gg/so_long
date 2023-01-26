/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:49:17 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 20:49:17 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *map)
{
	t_map	*ptr;

	while (map != NULL)
	{
		ptr = map;
		map = map->next;
		free(ptr->row);
		free(ptr);
	}
}

void	ft_free_data(t_base *data)
{
	ft_free_map(data->map);
}
