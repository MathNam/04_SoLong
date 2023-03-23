/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:57:21 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/22 14:28:13 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
