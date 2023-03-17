/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:57:21 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/17 18:42:56 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_end_game(t_game *data)
{
	int	w;
	int	h;

	data->img.end[0] = mlx_xpm_file_to_image(data->ptr, E0, &w, &h);
	data->img.end[1] = mlx_xpm_file_to_image(data->ptr, E1, &w, &h);
	data->img.end[2] = mlx_xpm_file_to_image(data->ptr, E2, &w, &h);
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
		mlx_put_image_to_window(data->ptr, data->win, data->img.end[1],
			data->width * IMG_W / 2 - 96, data->height * IMG_H / 2 - 96);
	else if (x < data->width)
	{
		data->map[y][x++].img = data->img.end[0];
		render_map(data);
	}
}
