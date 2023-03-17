/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:29:45 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/17 18:42:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_image_v2(void *mlx_ptr, void *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx_ptr, img);
}
