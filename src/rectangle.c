/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:51:56 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 12:15:51 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_base *data)
{
	t_map	*map;
	size_t	len;

	map = data->map;
	len = ft_strlen(map->row);
	while (map != NULL)
	{
		if (len != ft_strlen(map->row) || len == 0)
			error_free(data, RECTANGLE_ERROR);
		map = map->next;
	}
}
