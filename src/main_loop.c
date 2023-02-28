/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:04:33 by ihashimo          #+#    #+#             */
/*   Updated: 2023/02/28 10:04:34 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	iscomplete(t_count *counts)
{
	if (counts->collect == counts->current)
		counts->status = COMPLETE;
}

static void	isgoal(t_base *data)
{
	if (data->counts.play == FINISH)
		end_game(data);
}

int	main_loop(t_base *data)
{
	iscomplete(&data->counts);
	draw_map(data);
	isgoal(data);
	return (0);
}
