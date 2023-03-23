/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:23 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/22 14:01:06 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sea_tile(t_game *data)
{
	int	x;
	int	y;

	data->map[0][0].img = data->img.map.s[4];
	data->map[0][data->width - 1].img = data->img.map.s[5];
	data->map[data->height - 1][0].img = data->img.map.s[6];
	data->map[data->height - 1][data->width - 1].img = data->img.map.s[7];
	x = 1;
	while (x < data->width - 1)
	{
		data->map[0][x].img = data->img.map.s[0];
		data->map[data->height - 1][x].img = data->img.map.s[1];
		x++;
	}
	y = 1;
	while (y < data->height - 1)
	{
		data->map[y][0].img = data->img.map.s[2];
		data->map[y][data->width - 1].img = data->img.map.s[3];
		y++;
	}
}

void	gnd_tile(t_game *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->height - 1)
	{
		x = 1;
		while (x < data->width - 1)
		{
			if (data->map[y][x].type == '0')
				data->map[y][x].img = data->img.map.f[(x / 4 + y / 2) % 2];
			if (data->map[y][x].type == '1')
				data->map[y][x].img = data->img.map.w[(x / 2 + y / 5) % 3];
			if (data->map[y][x].type == 'C')
				data->map[y][x].img = data->img.map.c[0];
			if (data->map[y][x].type == 'P')
				data->map[y][x].img = data->img.map.io[0];
			if (data->map[y][x].type == 'E')
				data->map[y][x].img = data->img.map.io[1];
			if (data->map[y][x].type == 'X')
				data->map[y][x].img = data->img.map.e[0];
			x++;
		}
		y++;
	}
}

void	generate_map(t_game *data)
{
	sea_tile(data);
	gnd_tile(data);
}
