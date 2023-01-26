#include "so_long.h"

void	print_step(t_count *counts)
{
	if (counts->move == MOVE)
		ft_printf("steps : %d\n", counts->walk);
	counts->move = STAY;
}
