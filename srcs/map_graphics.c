/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:23 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/02 18:01:23 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	link_sea_img(t_game *data)
{
	int	w;
	int h;
	
	data->spt.s[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/std_tile.xpm", &w, &h);
	data->spt.s[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/left.xpm", &w, &h);
	data->spt.s[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/top.xpm", &w, &h);
	data->spt.s[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/right.xpm", &w, &h);
	data->spt.s[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/bottom.xpm", &w, &h);
	data->spt.s[5] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/top_left.xpm", &w, &h);
	data->spt.s[6] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/top_right.xpm", &w, &h);
	data->spt.s[7] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/bottom_left.xpm", &w, &h);
	data->spt.s[8] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/bottom_right.xpm", &w, &h);
	data->spt.s[9] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/top_left_angle.xpm", &w, &h);
	data->spt.s[10] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/top_right_angle.xpm", &w, &h);
	data->spt.s[11] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/bottom_left_angle.xpm", &w, &h);
	data->spt.s[12] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sea/bottom_right_angle.xpm", &w, &h);
}

void	link_map_img(t_game *data)
{
	int	w;
	int h;

	data->spt.e[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/io/entry.xpm", &w, &h);
	data->spt.e[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/io/exit_closed.xpm", &w, &h);
	data->spt.e[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/io/exit_open.xpm", &w, &h);
	data->spt.f[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/floor/std_0", &w, &h);
	data->spt.f[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/floor/std_1", &w, &h);
	data->spt.f[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/floor/std_2", &w, &h);
	data->spt.c[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/collect/closed.xpm", &w, &h);
	data->spt.c[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/collect/open.xpm", &w, &h);
	data->spt.w[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall/hole.xpm", &w, &h);
	data->spt.w[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall/mountain.xpm", &w, &h);
	data->spt.w[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall/stone.xpm", &w, &h);
}

void	*find_image(t_game *data, int x, int y)
{
	
}

void	generate_map(t_game *data)
{
	int	x;
	int	y;

	link_map_img(data);
	link_sea_img(data);
	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->map[y][x].img = find_image(data, x, y);
			x++;
		}
		y++;
	}
}