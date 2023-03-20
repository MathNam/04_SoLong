/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:20:21 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/20 17:38:38 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_point **map, int height)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < height && map[y])
		free(map[y++]);
	free(map);
}


void	destroy_image_v2(void *mlx_ptr, void *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx_ptr, img);
}

int		destroy_images(t_game *data)
{
	void	**p;
	int		i;

	p = (void **)&data->img;
	i = 0;
	while (i < IMG_NB)
		destroy_image_v2(data->ptr, p[i++]);
	return (0);
}

void	free_game(t_game *data)
{
	if (!data)
		return ;
	if (data->ptr)
		free(data->ptr);
	free_map(data->map, data->height);
	free(data);
}

int	exit_game(t_game *data)
{
	if (!data)
		return (0);
	if (data->ptr)
	{
		destroy_images(data);
		if (data->win)
		{
			mlx_clear_window(data->ptr, data->win);
			mlx_destroy_window(data->ptr, data->win);
		}
		mlx_destroy_display(data->ptr);
		free(data->ptr);
	}
	free_map(data->map, data->height);
	free(data);
	exit(0);
	return (0);
}
