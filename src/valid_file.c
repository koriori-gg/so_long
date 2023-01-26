/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:57:31 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/26 17:04:31 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file(char *arg)
{
	char	*ptr;
	int		fd;

	ptr = ft_strrchr(arg , '.');
	if (ptr == NULL)
		error();
	if (ft_memcmp(ptr, ".ber", 4) != 0)
		error();
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		close(fd);//TODO:-1の場合する必要ある？？
		error();	
	}
	close(fd);
}
