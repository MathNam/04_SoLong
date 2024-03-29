/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:29:45 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/22 14:02:51 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	*find_point(t_game *data, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x].type == c)
				return (&data->map[y][x]);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	print_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x == data->p1.x && y == data->p1.y)
				write(1, "P", 1);
			else
				write(1, &data->map[y][x].type, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
