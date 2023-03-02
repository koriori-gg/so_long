/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:18:50 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 21:56:04 by ihashimo         ###   ########.fr       */
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

static char	*check_line_feed(char *str)
{
	char	*new;

	if (ft_strchr(str, '\n'))
		new = strdup(str);
	else
		new = ft_strjoin(str, "\n");
	free(str);
	return (new);
}

void	input_map(t_map **map, char **argv)
{
	int		fd;
	char	*str;
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
		str = check_line_feed(str);
		if (i == 1)
			*map = ft_mapnew(str);
		else
			ft_mapadd_back(map, ft_mapnew(str));
		i++;
	}
	close(fd);
}
// void	print_map(t_map *map)
// {
// 	t_map	*node;

// 	node = map;
// 	while (node != NULL)
// 	{
// 		printf("%s", node->row);
// 		node = node->next;
// 	}
// }