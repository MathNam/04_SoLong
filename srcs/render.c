/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:37 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/06 19:01:32 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	xpm_player(t_game *data)
{
	int	w;
	int h;

	data->spt.p[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/player.xpm", &w, &h);
}

void	render_map(t_game *data)
{	
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->map[y][x].img, x * IMG_W, y * IMG_H);
			x++;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->spt.p[0], 3 * IMG_W + 32, 3 * IMG_H + 32);
		}
		y++;
	}
}