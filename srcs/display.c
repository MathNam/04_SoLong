/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:37 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/22 14:27:27 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *data)
{	
	static int	fno;
	int			x;
	int			y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x].type == 'X' && fno % 16 == 0 && data->end == 0)
				data->map[y][x].img = data->img.map.e[2 - fno / 16];
			mlx_put_image_to_window(data->ptr, data->win,
				data->map[y][x].img, x * IMG_W, y * IMG_H);
			x++;
		}
		y++;
	}
	fno++;
	fno = fno % 48;
}

void	end_screen(t_game *data)
{
	static int	x;
	static int	y;

	if (x == data->width && y < data->height)
	{
		x = 0;
		y++;
	}
	if (y == data->height)
	{
		if (data->end == 1)
			mlx_put_image_to_window(data->ptr, data->win, data->img.end[1],
				data->width * IMG_W / 2 - 96, data->height * IMG_H / 2 - 96);
		if (data->end == 2)
			mlx_put_image_to_window(data->ptr, data->win, data->img.end[2],
				data->width * IMG_W / 2 - 96, data->height * IMG_H / 2 - 96);
	}
	else if (x < data->width)
	{
		data->map[y][x++].img = data->img.end[0];
		render_map(data);
	}
}
