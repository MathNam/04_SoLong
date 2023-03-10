/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:37 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/10 13:38:43 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		}
		y++;
	}
}
