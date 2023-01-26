/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:47:05 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 16:52:47 by ihashimo         ###   ########.fr       */
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
	char	*str_up;
	char	*str;
	char	*str_down;

	str_up = map->prev->row;
	str = map->row;
	str_down = map->next->row;
	if ((str_up[i] == '1') && (str[i + 1] == '1') 
		&& (str[i - 1] == '1') && (str_down[i] == '1'))
		return ;
	if (str[i + 1] != '1')
	{
		str[i + 1] = '1';
		backtracking(map, i + 1);
	}
	if (str[i - 1] != '1')
	{
		str[i - 1] = '1';
		backtracking(map, i - 1);
	}
	if (str_down[i] != '1')
	{
		str_down[i] = '1';
		backtracking(map->next, i);
	}
	if (str_up[i] != '1')
	{
		str_up[i] = '1';
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
				error_free(data);
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
			break;
		i++;
		dup = dup->next;
	}
	backtracking(dup, data->index.x);
	print_map(test);
	dup_contain(data, dup, "01PE\n");//CE->1//error reason
	ft_free_map(dup);//TODO: 関数にする必要あり？？
}
