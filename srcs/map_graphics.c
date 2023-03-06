/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:23 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/06 18:57:43 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_sea_to_img(t_game *data)
{
	int	w;
	int h;

	data->spt.s[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/left.xpm", &w, &h);
	data->spt.s[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/top.xpm", &w, &h);
	data->spt.s[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/right.xpm", &w, &h);
	data->spt.s[3] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/bottom.xpm", &w, &h);
	data->spt.s[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/top_left.xpm", &w, &h);
	data->spt.s[5] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/top_right.xpm", &w, &h);
	data->spt.s[6] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/bottom_left.xpm", &w, &h);
	data->spt.s[7] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/sea/bottom_right.xpm", &w, &h);
}

void	xpm_map_to_img(t_game *data)
{
	int	w;
	int h;

	data->spt.io[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/io/entry.xpm", &w, &h);
	data->spt.io[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/io/exit_closed.xpm", &w, &h);
	data->spt.io[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/io/exit_open.xpm", &w, &h);
	data->spt.f[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor/std_0.xpm", &w, &h);
	data->spt.f[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor/std_1.xpm", &w, &h);
	data->spt.f[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor/std_2.xpm", &w, &h);
	data->spt.c[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/collect/closed.xpm", &w, &h);
	data->spt.c[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/collect/open.xpm", &w, &h);
	data->spt.w[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall/hole.xpm", &w, &h);
	data->spt.w[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall/mountain.xpm", &w, &h);
	data->spt.w[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall/stone.xpm", &w, &h);
}

void	sea_tile(t_game *data)
{
	int	x;
	int	y;

	data->map[0][0].img = data->spt.s[4];
	data->map[0][data->width - 1].img = data->spt.s[5];
	data->map[data->height - 1][0].img = data->spt.s[6];
	data->map[data->height - 1][data->width - 1].img = data->spt.s[7];
	x = 1;
	while (x < data->width - 1)
	{
		data->map[0][x].img = data->spt.s[1];
		data->map[data->height - 1][x].img = data->spt.s[3];
		x++;
	}
	y = 1;
	while (y < data->height - 1)
	{
		data->map[y][0].img = data->spt.s[0];
		data->map[y][data->width - 1].img = data->spt.s[2];
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
				data->map[y][x].img = data->spt.f[(x / 4 + y / 2) % 2];
			if (data->map[y][x].type == '1')
				data->map[y][x].img = data->spt.w[(x / 2 + y / 5) % 3];
			if (data->map[y][x].type == 'C')
				data->map[y][x].img = data->spt.c[0];
			if (data->map[y][x].type == 'P')
				data->map[y][x].img = data->spt.io[0];
			if (data->map[y][x].type == 'E')
				data->map[y][x].img = data->spt.io[1];
			x++;
		}
		y++;
	}
}

void	generate_map(t_game *data)
{
	xpm_sea_to_img(data);
	xpm_map_to_img(data);
	sea_tile(data);
	gnd_tile(data);
}