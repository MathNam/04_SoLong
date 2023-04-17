/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:26:29 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 17:37:08 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
