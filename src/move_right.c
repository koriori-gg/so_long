/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:58:03 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 17:15:06 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_right(t_map *ptr, t_index *index, t_count *counts)
{
	if (counts->status == INCOMPLETE && ptr->row[index->x + 1] == 'E')
	{
		ptr->row[index->x + 1] = 'P';
		ptr->row[index->x] = '0';
		index->x += 1;
		counts->step += 1;
		counts->move = MOVE;
		counts->before = EXIT;		
		return ;
	}
	if (counts->status == COMPLETE && ptr->row[index->x + 1] == 'E')
		counts->play = FINISH;
	if (ptr->row[index->x + 1] == 'C')
		counts->current += 1;
	ptr->row[index->x + 1] = 'P';
	ptr->row[index->x] = '0';
	if (counts->before == EXIT)
	{
		ptr->row[index->x] = 'E';
		counts->before = OTHER;
	}
	index->x += 1;
	counts->step += 1;
	counts->move = MOVE;
}

void	move_right(t_map *map, t_index *index, t_count *counts)
{
	t_map	*ptr;
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
	if (ft_strchr("0CE", ptr->row[index->x + 1]) == NULL)
		return ;
	update_right(ptr, index, counts);
}