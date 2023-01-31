/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:47:05 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/31 10:48:47 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*mapdup(t_map *map)
{
	t_map	*ret;
	size_t	i;

	i = 0;
	while (map != NULL)
	{
		if (i == 0)
			ret = ft_mapnew(ft_strdup(map->row));
		else
			ft_mapadd_back(&ret, ft_mapnew(ft_strdup(map->row)));
		i++;
		map = map->next;
	}
	return (ret);
}

static void	backtracking(t_map *map, int i)
{
	if ((map->prev->row[i] == '1') && (map->row[i + 1] == '1')
		&& (map->row[i - 1] == '1') && (map->next->row[i] == '1'))
		return ;
	if (map->row[i + 1] != '1')
	{
		map->row[i + 1] = '1';
		backtracking(map, i + 1);
	}
	if (map->row[i - 1] != '1')
	{
		map->row[i - 1] = '1';
		backtracking(map, i - 1);
	}
	if (map->next->row[i] != '1')
	{
		map->next->row[i] = '1';
		backtracking(map->next, i);
	}
	if (map->prev->row[i] != '1')
	{
		map->prev->row[i] = '1';
		backtracking(map->prev, i);
	}
}

static void	dup_contain(t_base *data, t_map *dup, char *chars)
{
	t_map	*map;
	size_t	i;
	char	*str;

	map = dup;
	while (map != NULL)
	{
		i = 0;
		str = map->row;
		while (str[i])
		{
			if (ft_strchr(chars, str[i]) == NULL)
			{
				ft_free_map(dup);
				error_free(data, NOTABLETOGOAL_ERROR);
			}
			i++;
		}
		map = map->next;
	}
}

void	able_to_goal(t_base *data)
{
	char	*str;
	t_map	*dup;
	t_map	*test;
	size_t	i;

	dup = mapdup(data->map);
	test = dup;
	i = 0;
	while (dup != NULL)
	{
		if (i == data->index.y)
			break ;
		i++;
		dup = dup->next;
	}
	backtracking(dup, data->index.x);
	dup_contain(data, dup, "01PE\n");
	ft_free_map(dup);
}
