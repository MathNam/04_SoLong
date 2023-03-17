/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:26:29 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/17 18:43:20 by maaliber         ###   ########.fr       */
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

void	print_mv_cnt(t_game *data, int mv_cnt)
{
	int	i;

	i = 0;
	while (mv_cnt)
	{
		mlx_put_image_to_window(data->ptr, data->win,
			data->img.num[mv_cnt % 10], data->width * IMG_W - 48 - 40 * i, 5);
		mv_cnt = mv_cnt / 10;
		i++;
	}
}
