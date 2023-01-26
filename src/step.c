/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:47:22 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 20:47:23 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_step(t_count *counts)
{
	if (counts->move == MOVE)
		ft_printf("steps : %d\n", counts->step);
	counts->move = STAY;
}
