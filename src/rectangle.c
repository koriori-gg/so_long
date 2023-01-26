/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:51:56 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 20:52:09 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	isrectangle(t_base *data)
{
	t_map	*map;
	size_t	len;

	map = data->map;
	len = ft_strlen(map->row);
	while (map != NULL)
	{	
		if (len != ft_strlen(map->row) || len == 0)
			error_free(data);
		map = map->next;
	}
}
