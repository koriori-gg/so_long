/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:04:33 by ihashimo          #+#    #+#             */
/*   Updated: 2023/03/02 12:27:08 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	toggle_if_needed(t_count *counts)
{
	if (counts->collect == counts->current)
		counts->status = COMPLETE;
}

static void	end_if_goal(t_base *data)
{
	if (data->counts.play == FINISH)
		end_game(data);
}

int	main_loop(t_base *data)
{
	toggle_if_needed(&data->counts);
	draw_map(data);
	end_if_goal(data);
	return (0);
}
