/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:42:04 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/22 14:01:31 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_p1_idle(t_game *data)
{
	int	w;
	int	h;

	data->img.p1.idle[0] = mlx_xpm_file_to_image(data->ptr, IDLE_L0, &w, &h);
	data->img.p1.idle[1] = mlx_xpm_file_to_image(data->ptr, IDLE_L1, &w, &h);
	data->img.p1.idle[2] = mlx_xpm_file_to_image(data->ptr, IDLE_L2, &w, &h);
	data->img.p1.idle[3] = mlx_xpm_file_to_image(data->ptr, IDLE_L3, &w, &h);
	data->img.p1.idle[4] = mlx_xpm_file_to_image(data->ptr, IDLE_L4, &w, &h);
	data->img.p1.idle[5] = mlx_xpm_file_to_image(data->ptr, IDLE_R0, &w, &h);
	data->img.p1.idle[6] = mlx_xpm_file_to_image(data->ptr, IDLE_R1, &w, &h);
	data->img.p1.idle[7] = mlx_xpm_file_to_image(data->ptr, IDLE_R2, &w, &h);
	data->img.p1.idle[8] = mlx_xpm_file_to_image(data->ptr, IDLE_R3, &w, &h);
	data->img.p1.idle[9] = mlx_xpm_file_to_image(data->ptr, IDLE_R4, &w, &h);
}

void	xpm_p1_move(t_game *data)
{
	int	w;
	int	h;

	data->img.p1.move[0] = mlx_xpm_file_to_image(data->ptr, MV_L0, &w, &h);
	data->img.p1.move[1] = mlx_xpm_file_to_image(data->ptr, MV_L1, &w, &h);
	data->img.p1.move[2] = mlx_xpm_file_to_image(data->ptr, MV_L2, &w, &h);
	data->img.p1.move[3] = mlx_xpm_file_to_image(data->ptr, MV_L3, &w, &h);
	data->img.p1.move[4] = mlx_xpm_file_to_image(data->ptr, MV_L4, &w, &h);
	data->img.p1.move[5] = mlx_xpm_file_to_image(data->ptr, MV_L5, &w, &h);
	data->img.p1.move[6] = mlx_xpm_file_to_image(data->ptr, MV_L6, &w, &h);
	data->img.p1.move[7] = mlx_xpm_file_to_image(data->ptr, MV_L7, &w, &h);
	data->img.p1.move[8] = mlx_xpm_file_to_image(data->ptr, MV_R0, &w, &h);
	data->img.p1.move[9] = mlx_xpm_file_to_image(data->ptr, MV_R1, &w, &h);
	data->img.p1.move[10] = mlx_xpm_file_to_image(data->ptr, MV_R2, &w, &h);
	data->img.p1.move[11] = mlx_xpm_file_to_image(data->ptr, MV_R3, &w, &h);
	data->img.p1.move[12] = mlx_xpm_file_to_image(data->ptr, MV_R4, &w, &h);
	data->img.p1.move[13] = mlx_xpm_file_to_image(data->ptr, MV_R5, &w, &h);
	data->img.p1.move[14] = mlx_xpm_file_to_image(data->ptr, MV_R6, &w, &h);
	data->img.p1.move[15] = mlx_xpm_file_to_image(data->ptr, MV_R7, &w, &h);
}

void	xpm_p1_special(t_game *data)
{
	int	w;
	int	h;

	data->img.p1.act[0] = mlx_xpm_file_to_image(data->ptr, ACT_C0, &w, &h);
	data->img.p1.act[1] = mlx_xpm_file_to_image(data->ptr, ACT_C1, &w, &h);
	data->img.p1.act[2] = mlx_xpm_file_to_image(data->ptr, ACT_C20, &w, &h);
	data->img.p1.act[3] = mlx_xpm_file_to_image(data->ptr, ACT_C21, &w, &h);
	data->img.p1.act[4] = mlx_xpm_file_to_image(data->ptr, ACT_C22, &w, &h);
	data->img.p1.act[5] = mlx_xpm_file_to_image(data->ptr, ACT_C3, &w, &h);
	data->img.p1.io[0] = mlx_xpm_file_to_image(data->ptr, P1_ENTRY, &w, &h);
	data->img.p1.io[1] = mlx_xpm_file_to_image(data->ptr, P1_EXIT_0, &w, &h);
	data->img.p1.io[2] = mlx_xpm_file_to_image(data->ptr, P1_EXIT_1, &w, &h);
}
