/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:42:01 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/22 14:01:17 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_num(t_game *data)
{
	int	w;
	int	h;

	data->img.num[0] = mlx_xpm_file_to_image(data->ptr, X0, &w, &h);
	data->img.num[1] = mlx_xpm_file_to_image(data->ptr, X1, &w, &h);
	data->img.num[2] = mlx_xpm_file_to_image(data->ptr, X2, &w, &h);
	data->img.num[3] = mlx_xpm_file_to_image(data->ptr, X3, &w, &h);
	data->img.num[4] = mlx_xpm_file_to_image(data->ptr, X4, &w, &h);
	data->img.num[5] = mlx_xpm_file_to_image(data->ptr, X5, &w, &h);
	data->img.num[6] = mlx_xpm_file_to_image(data->ptr, X6, &w, &h);
	data->img.num[7] = mlx_xpm_file_to_image(data->ptr, X7, &w, &h);
	data->img.num[8] = mlx_xpm_file_to_image(data->ptr, X8, &w, &h);
	data->img.num[9] = mlx_xpm_file_to_image(data->ptr, X9, &w, &h);
}

void	xpm_end_game(t_game *data)
{
	int	w;
	int	h;

	data->img.end[0] = mlx_xpm_file_to_image(data->ptr, E0, &w, &h);
	data->img.end[1] = mlx_xpm_file_to_image(data->ptr, E1, &w, &h);
	data->img.end[2] = mlx_xpm_file_to_image(data->ptr, E2, &w, &h);
}

void	xpm_map_sea(t_game *data)
{
	int	w;
	int	h;

	data->img.map.s[0] = mlx_xpm_file_to_image(data->ptr, SEA_T, &w, &h);
	data->img.map.s[1] = mlx_xpm_file_to_image(data->ptr, SEA_B, &w, &h);
	data->img.map.s[2] = mlx_xpm_file_to_image(data->ptr, SEA_L, &w, &h);
	data->img.map.s[3] = mlx_xpm_file_to_image(data->ptr, SEA_R, &w, &h);
	data->img.map.s[4] = mlx_xpm_file_to_image(data->ptr, SEA_TL, &w, &h);
	data->img.map.s[5] = mlx_xpm_file_to_image(data->ptr, SEA_TR, &w, &h);
	data->img.map.s[6] = mlx_xpm_file_to_image(data->ptr, SEA_BL, &w, &h);
	data->img.map.s[7] = mlx_xpm_file_to_image(data->ptr, SEA_BR, &w, &h);
}

void	xpm_map_ground(t_game *data)
{
	int	w;
	int	h;

	data->img.map.f[0] = mlx_xpm_file_to_image(data->ptr, GND_0, &w, &h);
	data->img.map.f[1] = mlx_xpm_file_to_image(data->ptr, GND_1, &w, &h);
	data->img.map.f[2] = mlx_xpm_file_to_image(data->ptr, GND_2, &w, &h);
	data->img.map.w[0] = mlx_xpm_file_to_image(data->ptr, WALL_0, &w, &h);
	data->img.map.w[1] = mlx_xpm_file_to_image(data->ptr, WALL_1, &w, &h);
	data->img.map.w[2] = mlx_xpm_file_to_image(data->ptr, WALL_2, &w, &h);
	data->img.map.io[0] = mlx_xpm_file_to_image(data->ptr, ENTRY, &w, &h);
	data->img.map.io[1] = mlx_xpm_file_to_image(data->ptr, EXIT_0, &w, &h);
	data->img.map.io[2] = mlx_xpm_file_to_image(data->ptr, EXIT_1, &w, &h);
	data->img.map.c[0] = mlx_xpm_file_to_image(data->ptr, LOOT_0, &w, &h);
	data->img.map.c[1] = mlx_xpm_file_to_image(data->ptr, LOOT_1, &w, &h);
	data->img.map.e[0] = mlx_xpm_file_to_image(data->ptr, SPK_0, &w, &h);
	data->img.map.e[1] = mlx_xpm_file_to_image(data->ptr, SPK_1, &w, &h);
	data->img.map.e[2] = mlx_xpm_file_to_image(data->ptr, SPK_2, &w, &h);
}

void	xpm_images(t_game *data)
{
	xpm_num(data);
	xpm_end_game(data);
	xpm_map_sea(data);
	xpm_map_ground(data);
	xpm_p1_idle(data);
	xpm_p1_move(data);
	xpm_p1_special(data);
}
