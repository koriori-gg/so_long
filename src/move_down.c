/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:59:21 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 17:15:05 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_down(t_map *dst, t_map *ptr, t_index *index, t_count *counts)
{
	if (counts->status == INCOMPLETE && dst->row[index->x] == 'E')
	{
		dst->row[index->x] = 'P';
		ptr->row[index->x] = '0';
		index->y += 1;
		counts->step += 1;
		counts->move = MOVE;
		counts->before = EXIT;
		return ;
	}
	if (counts->status == COMPLETE && dst->row[index->x] == 'E')
		counts->play = FINISH;
	if (dst->row[index->x] == 'C')
		counts->current += 1;
	dst->row[index->x] = 'P';
	ptr->row[index->x] = '0';
	if (counts->before == EXIT)
	{
		ptr->row[index->x] = 'E';
		counts->before = OTHER;
	}
	index->y += 1;
	counts->step += 1;
	counts->move = MOVE;
}

void	move_down(t_map *map, t_index *index, t_count *counts)
{
	t_map	*ptr;
	t_map	*dst;
	int		i;

	ptr = map;
	i = 0;
	while (ptr != NULL)
	{
		if (i == index->y)
			break;
		ptr = ptr->next;
		i++;
	}
	dst = ptr->next;
	if (ft_strchr("0CE", dst->row[index->x]) == NULL)
		return ;
	update_down(dst, ptr, index, counts);
}
