/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:20:21 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/13 17:00:02 by maaliber         ###   ########.fr       */
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

void	free_game(t_game *data)
{
	if (!data)
		return ;
	free_map(data->map, data->height);
	free(data);
}

void	destroy_tiles(t_game *data)
{
	int i;
	
	i = 0;
	while (i < 3)
		mlx_destroy_image(data->mlx_ptr, data->img.map.f[i++]);
	i = 0;
	while (i < 8)
		mlx_destroy_image(data->mlx_ptr, data->img.map.s[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(data->mlx_ptr, data->img.map.w[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(data->mlx_ptr, data->img.map.io[i++]);
	i = 0;
	while (i < 2)
		mlx_destroy_image(data->mlx_ptr, data->img.map.c[i++]);
}

void	destroy_sprites(t_game *data)
{
	int i;
	
	i = 0;
	while (i < 10)
		mlx_destroy_image(data->mlx_ptr, data->img.p1.idle[i++]);
	i = 0;
	while (i < 16)
		mlx_destroy_image(data->mlx_ptr, data->img.p1.move[i++]);
	i = 0;
	while (i < 6)
		mlx_destroy_image(data->mlx_ptr, data->img.p1.act[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(data->mlx_ptr, data->img.p1.io[i++]);
}
