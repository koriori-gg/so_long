/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:47:15 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/25 14:46:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// void	error()
// {
// 	write(1,"error\n",6);
// 	exit(1);
// }

size_t	strcount(char *str, char c)
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
void	contains_char(t_map *map, t_count *counts)
{
	size_t	start;
	size_t	exit;
	size_t	collect;

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
		error();
	counts->collect = collect;
}

void	isrectangle(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->row);
	while (map != NULL)
	{	
		if (len != ft_strlen(map->row) || len == 0)
			error();
		map = map->next;
	}
}

void	contains_unnecessary(t_map *map, char *chars)
{
	size_t	i;
	char	*str;


	while (map != NULL)
	{
		i = 0;
		str = map->row;
		while (str[i])
		{
			if (ft_strchr(chars, str[i]) == NULL)
				error();
			i++;
		}
		map = map->next;
	}

}
void	issurrounded(t_map *map, int map_height, int map_width)
{
	int	i;
	int	j;

	i = 0;
	while (map != NULL)
	{
		j = 0;
		while (map->row[j] != '\n')
		{
			if (i == 0 || i + 1 == map_height)
			{
				if (map->row[j] != '1')
					error();
			}
			else
			{
				if((j == 0 || j + 1 == map_width) &&  map->row[j] != '1')
					error();
			}
			j++;
		}
		i++;
		map = map->next;
	}
}



void	isvalid_map(t_base *data)
{
	isrectangle(data->map);
	contains_char(data->map, &data->counts);
	contains_unnecessary(data->map, "01CEP\n");
	issurrounded(data->map, data->map_height, data->map_width);
	able_to_goal(data->map, &data->index);
}