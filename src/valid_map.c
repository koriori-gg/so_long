/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:47:15 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 16:50:11 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void	contains_char(t_base *data)
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
		error_free(data);
	data->counts.collect = collect;
}

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

void	contains_unnecessary(t_base *data, char *chars)
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
				error_free(data);
			i++;
		}
		map = map->next;
	}
}

void	issurrounded(t_base *data)
{
	t_map	*map;
	int		height;
	int		width;
	int		i;
	int		j;

	map = data->map;
	height = data->image_height;
	width = data->image_width;
	i = 0;
	while (map != NULL)
	{
		j = 0;
		while (map->row[j] != '\n')
		{
			if (i == 0 || i + 1 == height)
			{
				if (map->row[j] != '1')
					error_free(data);
			}
			else
			{
				if((j == 0 || j + 1 == width) &&  map->row[j] != '1')
					error_free(data);
			}
			j++;
		}
		i++;
		map = map->next;
	}
}

void	isvalid_map(t_base *data)
{
	isrectangle(data);
	contains_char(data);
	contains_unnecessary(data, "01CEP\n");
	issurrounded(data);
	able_to_goal(data);
}