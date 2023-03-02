/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:47:15 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 15:45:43 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	strcount(char *str, char c)
{
	size_t	i;
	size_t	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	contains_char(t_base *data)
{
	t_map	*map;
	size_t	start;
	size_t	exit;
	size_t	collect;

	map = data->map;
	start = 0;
	exit = 0;
	collect = 0;
	while (map != NULL)
	{
		start += strcount(map->row, 'P');
		exit += strcount(map->row, 'E');
		collect += strcount(map->row, 'C');
		map = map->next;
	}
	if (start != 1 || exit != 1 || collect < 1)
		error_free(data, MINIMUM_ERROR);
	data->counts.collect = collect;
}

static void	contains_unnecessary(t_base *data, char *chars)
{
	t_map	*map;
	size_t	i;
	char	*str;

	map = data->map;
	while (map != NULL)
	{
		i = 0;
		str = map->row;
		while (str[i])
		{
			if (ft_strchr(chars, str[i]) == NULL)
				error_free(data, UNNESSESARY_ERROR);
			i++;
		}
		map = map->next;
	}
}

static void	check_surrounded(t_base *data)
{
	t_map	*map;
	int		i;
	int		j;

	map = data->map;
	i = 1;
	while (map != NULL)
	{
		j = 0;
		while (map->row[j] != '\n')
		{
			if ((i == 1 || i == data->map_height) && (map->row[j] != '1'))
				error_free(data, SURROUND_ERROR);
			else if ((i != 1 && i != data->map_height)
				&& (j == 0 || j + 1 == data->map_width) && map->row[j] != '1')
				error_free(data, SURROUND_ERROR);
			j++;
		}
		i++;
		map = map->next;
	}
}

void	check_valid_map(t_base *data)
{
	check_rectangle(data);
	contains_char(data);
	contains_unnecessary(data, "01CEP\n");
	check_surrounded(data);
	able_to_goal(data);
}
