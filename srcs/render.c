/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:37 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/20 16:04:01 by maaliber         ###   ########.fr       */
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
			if (data->map[y][x].type == 'X' && fno % 16 == 0)
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
