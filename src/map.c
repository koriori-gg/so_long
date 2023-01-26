/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:50 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 16:48:47 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_mapnew(char *str)
{
	t_map	*ret;

	ret = ft_calloc(1, sizeof(t_map));
	if (!ret)
		return (NULL);
	ret->row = str;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

int	ft_mapsize(t_map *map)
{
	int	size;

	size = 0;
	if (!map)
		return (0);
	while (map->next != NULL)
	{
		size++;
		map = map->next;
	}
	return (size + 1);
}

void	ft_mapadd_back(t_map **map, t_map *new)
{
	t_map	*ptr;
	int		size;

	if (!*map)
		*map = new;
	else
	{
		ptr = *map;
		size = ft_mapsize(*map);
		while (size > 1)
		{
			ptr = ptr->next;
			size--;
		}
		ptr->next = new;
		new->prev = ptr;
	}
}

void	input_map(t_map **map, char **argv)
{
	int		fd;
	char	*str;
	char	*temp;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			break ;
		}
		if (!ft_strchr(str, '\n'))
		{
			temp = ft_strjoin(str, "\n");
			free(str);
			str = temp;
		}
		if (i == 1)
			*map = ft_mapnew(str);
		else
			ft_mapadd_back(map, ft_mapnew(str));
		i++;
	}
	close(fd);
}
//TODO: 不要
void print_map(t_map *map)
{
	t_map *node;

	node = map;
	while (node != NULL)
	{
		printf("%s", node->row);
		node = node->next;
	}
}